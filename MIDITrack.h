#ifndef MIDITRACK_H_
#define MIDITRACK_H_

#include "MIDIChunk.h"
#include "MIDIChannelEvent.h"
#include "MIDIMetaEvent.h"

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

  char* data2cstr(int data[],int length);

  char* _data;
  dword _size;
  dword _pos;

  vector<MIDIChannelEvent*> _channelEvents;
  vector<MIDIMetaEvent*> _metaEvents;
};

#endif // MIDITRACK_H_
