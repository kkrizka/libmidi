#include "MIDIDataBuffer.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIDataBuffer::MIDIDataBuffer()
  : _data(0),_size(0),_maxsize(0),_pos(0)
{ }

MIDIDataBuffer::MIDIDataBuffer(const MIDIDataBuffer& o)
  : _size(o._size),_maxsize(o._maxsize),_pos(o._pos)
{
  _data=new byte[_maxsize];
  for(int i=0;i<_maxsize;i++)
    if(i<_size)
      _data[i]=o._data[i];
    else
      _data[i]='\0';
}

MIDIDataBuffer::MIDIDataBuffer(byte data[],unsigned int size)
  : _data(0),_size(size),_maxsize(size),_pos(0)
{ 
  _data=new byte[_maxsize];
  for(int i=0;i<_maxsize;i++)
    _data[i]=data[i];
}

MIDIDataBuffer::MIDIDataBuffer(unsigned int maxsize)
  : _data(new byte[maxsize]),_size(0),_maxsize(maxsize),_pos(0)
{
  for(int i=0;i<_maxsize;i++)
    _data[i]='\0';
 }

byte* MIDIDataBuffer::data()
{
  return _data;
}

unsigned int MIDIDataBuffer::size()
{
  return _size;
}

unsigned int MIDIDataBuffer::maxsize()
{
  return _maxsize;
}

void MIDIDataBuffer::writeVariableLength(dword data)
{
  //cout << "MIDIDataBuffer::writeVariableLength(dword data=0x" << setbase(16) << data << ")" << endl;
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


void MIDIDataBuffer::write(byte data)
{
  //cout << "MIDIDataBuffer::write(byte data=0x"<<setbase(16)<<(unsigned int)data<<")" << endl;
  if(_size+1>_maxsize) return;

  _data[_pos]=data;
  _pos++;
  _size+=1;
}

void MIDIDataBuffer::write(byte* data,unsigned int size)
{
  //cout << "MIDIDataBuffer::write(byte* data,unsigned int size="<<size<<")" << endl;
  if(_size+size>_maxsize) return;

  for(int i=0;i<size;i++)
    {
      _data[_pos]=data[i];
      _pos++;
    }
  _size+=size;
}

void MIDIDataBuffer::write(MIDIDataBuffer data)
{
  //cout << "MIDIDataBuffer::write(MIDIDataBuffer data)" << endl;
  write(data.data(),data.size());
}

void MIDIDataBuffer::seek(int pos)
{
  _pos=pos;
}

void MIDIDataBuffer::remove(int numBytes)
{
  for(int i=_pos+numBytes;i<_size;i++)
    {
      _data[i-numBytes]=_data[i];
    }

  _size-=numBytes;
  if(_size<0) _size=0;
}
