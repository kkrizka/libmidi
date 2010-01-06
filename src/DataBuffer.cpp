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

#include "DataBuffer.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  DataBuffer::DataBuffer()
    : _data(0),_size(0),_maxsize(0),_pos(0)
  { }
  
  DataBuffer::DataBuffer(const DataBuffer& o)
    : _size(o._size),_maxsize(o._maxsize),_pos(o._pos)
  {
    _data=new byte[_maxsize];
    for(int i=0;i<_maxsize;i++)
      if(i<_size)
	_data[i]=o._data[i];
      else
	_data[i]='\0';
  }
  
  DataBuffer::DataBuffer(byte data[],unsigned int size)
    : _data(0),_size(size),_maxsize(size),_pos(0)
  { 
    _data=new byte[_maxsize];
    for(int i=0;i<_maxsize;i++)
      _data[i]=data[i];
  }
  
  DataBuffer::DataBuffer(unsigned int maxsize)
    : _data(new byte[maxsize]),_size(0),_maxsize(maxsize),_pos(0)
  {
    for(int i=0;i<_maxsize;i++)
      _data[i]='\0';
  }
  
  byte* DataBuffer::data()
  {
    return _data;
  }
  
  unsigned int DataBuffer::size()
  {
    return _size;
  }
  
  unsigned int DataBuffer::maxsize()
  {
    return _maxsize;
  }
  
  void DataBuffer::writeVariableLength(dword data)
  {
    //cout << "DataBuffer::writeVariableLength(dword data=0x" << setbase(16) << data << ")" << endl;
    byte bytedata[4];
    // Fill the data array, assuming continuation
    for(int i=0;i<4;i++)
      {
	bytedata[i]=(0x7F & data)+0x80;
	data=(data>>7);
      }
    bytedata[0]=(bytedata[0]&0x7F); // The last piece is definitly not continious
    
    // Clacualte size
    int i;
    for(i=3;i>=1;i--)
      {
	if((bytedata[i] & 0x7F)!=0)
	  break;
      }
    for(i;i>=0;i--)
      write(bytedata[i]);
  }
  
  
  void DataBuffer::write(byte data)
  {
    //cout << "DataBuffer::write(byte data=0x"<<setbase(16)<<(unsigned int)data<<")" << endl;
    if(_size+1>_maxsize) return;
    
    _data[_pos]=data;
    _pos++;
    _size+=1;
  }
  
  void DataBuffer::write(byte* data,unsigned int size)
  {
    //cout << "DataBuffer::write(byte* data,unsigned int size="<<size<<")" << endl;
    if(_size+size>_maxsize) return;
    
    for(int i=0;i<size;i++)
      {
	_data[_pos]=data[i];
	_pos++;
      }
    _size+=size;
  }
  
  void DataBuffer::write(DataBuffer data)
  {
    //cout << "DataBuffer::write(DataBuffer data)" << endl;
    write(data.data(),data.size());
  }
  
  void DataBuffer::seek(int pos)
  {
    _pos=pos;
  }
  
  void DataBuffer::remove(int numBytes)
  {
    for(int i=_pos+numBytes;i<_size;i++)
      {
	_data[i-numBytes]=_data[i];
      }
    
    _size-=numBytes;
    if(_size<0) _size=0;
  }
}
