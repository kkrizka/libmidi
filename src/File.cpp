/*
  Copyright (C) 2010 Karol Krizka <kkrizka@gmail.com>
  
  URL: http://www.krizka.net/projects/libmidi/
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  $Id$
*/

#include "File.h"

#include <iostream>
#include <fstream>
using namespace std;

#include <string.h>

#include "Header.h"
#include "Track.h"

#include "DataBuffer.h"

#include "types.h"

namespace MIDI
{
  File::File(string path)
    : _path(path),_header(new Header())
  { }
  
  void File::setPath(string path)
  {
    _path=path;
  }
  
  unsigned int File::numTracks()
  {
    return _tracks.size();
  }
  
  Header* File::header()
  {
    return _header;
  }
  
  Track* File::track(unsigned int id)
  {
    return _tracks[id];
  }
  
  void File::addTrack(Track* track)
  {
    _tracks.push_back(track);
    _header->setNumTracks(_tracks.size());
  }
  
  Chunk* File::readChunk(ifstream& fh)
  {
    byte chunkID[5];
    dword chunkSize;
    byte buffer[100000];
    
    // Read the header ID, suiffix \0 to make it a proper C-string
    fh.read((char*)chunkID,4);
    chunkID[4]='\0';
    
    // Read the chunk size, using buffer as a temporary hold and the converting it to a dword
    fh.read((char*)buffer,4);
    chunkSize=byte2dword(buffer);
    
    // Read the data of the chunk, size found in the previous step
    fh.read((char*)buffer,chunkSize);
    //cout << chunkID << " " << chunkSize << endl;
    
    Chunk *ret=0;
    if(strcmp((char*)chunkID,"MThd")==0)
      ret=new Header(buffer,chunkSize);
    else if(strcmp((char*)chunkID,"MTrk")==0)
      ret=new Track(buffer,chunkSize);
    else
      ret=0;
    
    return ret;
  }
  
  bool File::open()
  {
    ifstream fh(_path.c_str(),ios::in | ios::binary);
    if(!fh.is_open()) return false; //Error check
    
    delete _header;
    _header=(Header*)readChunk(fh);
    
    for(int i=0;i<_header->numTracks();i++)
      {
	Track* track=(Track*)readChunk(fh);
	_tracks.push_back(track);
      }
    
    fh.close();
    return true;
  }
  
  bool File::write()
  {
    ofstream fh(_path.c_str(),ios::out | ios::binary);
    if(!fh.is_open()) return false; //Error check
    
    DataBuffer headerData=_header->data();
    
    fh.write("MThd",4);
    fh.write((char*)dword2byte(headerData.size()),4);
    fh.write((char*)headerData.data(),headerData.size());
    
    for(int i=0;i<_header->numTracks();i++)
      {
	Track* track=_tracks[i];
	DataBuffer trackData=track->data();
	
	fh.write("MTrk",4);
	fh.write((char*)dword2byte(trackData.size()),4);
	fh.write((char*)trackData.data(),trackData.size());
      }
    
    fh.close();
    return true;   
  }
}
