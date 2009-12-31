#include "MIDIFile.h"

#include <iostream>
#include <fstream>
using namespace std;

#include <string.h>

#include "MIDIHeader.h"
#include "MIDITrack.h"

#include "types.h"

MIDIFile::MIDIFile(string path)
  : _path(path),_header(0)
{ }

unsigned int MIDIFile::numTracks()
{
  return _tracks.size();
}

MIDIHeader* MIDIFile::header()
{
  return _header;
}

MIDITrack* MIDIFile::track(unsigned int id)
{
  return _tracks[id];
}

MIDIChunk* MIDIFile::readChunk(ifstream& fh)
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

  MIDIChunk *ret=0;
  if(strcmp((char*)chunkID,"MThd")==0)
    ret=new MIDIHeader(buffer,chunkSize);
  else if(strcmp((char*)chunkID,"MTrk")==0)
    ret=new MIDITrack(buffer,chunkSize);
  else
    ret=0;

  return ret;
}

bool MIDIFile::open()
{
  ifstream fh(_path.c_str(),ios::in | ios::binary);
  if(!fh.is_open()) return false; //Error check

  _header=(MIDIHeader*)readChunk(fh);

  for(int i=0;i<_header->numTracks();i++)
    {
      MIDITrack* track=(MIDITrack*)readChunk(fh);
      _tracks.push_back(track);
    }

  fh.close();
  return true;
}
