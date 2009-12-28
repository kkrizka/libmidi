#ifndef MIDITRACK_H_
#define MIDITRACK_H_

#include "MIDIChunk.h"
#include "MIDIChannelEvent.h"

#include <vector>
using namespace std;

class MIDITrack : public MIDIChunk
{
public:
  MIDITrack(char* data,dword size);

private:
  int readNextVariableLength();
  int readNext();

  void handleMetaEvent(int type,int data[],int length);

  void handleControllerEvent(int type,int value);

  char* data2cstr(int data[],int length);
  //int readEvent(int start,char* data,int size);

  char* _data;
  dword _size;
  dword _pos;

  vector<MIDIChannelEvent> _channelEvents;
};

#endif // MIDITRACK_H_
