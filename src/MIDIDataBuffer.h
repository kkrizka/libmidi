#ifndef MIDIDATABUFFER_H_
#define MIDIDATABUFFER_H_

#include "types.h"

class MIDIDataBuffer
{
public:
  MIDIDataBuffer();
  MIDIDataBuffer(const MIDIDataBuffer& o);
  MIDIDataBuffer(byte data[],unsigned int size);
  MIDIDataBuffer(unsigned int maxsize);

  byte* data();
  unsigned int size();
  unsigned int maxsize();

  void writeVariableLength(dword data);
  void write(byte data);
  void write(byte* data,unsigned int size);
  void write(MIDIDataBuffer data);

  void seek(int pos);

  void remove(int numBytes);

private:
  byte* _data;
  unsigned int _size;
  unsigned int _maxsize;

  unsigned int _pos;
};

#endif // MIDIDATABUFFER_H_
