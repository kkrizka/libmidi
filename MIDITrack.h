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
  MIDITrack(byte* data,dword size);

private:
  dword readNextVariableLength();
  byte readNextByte();

  void handleMetaEvent(int type,int data[],int length);

  byte* _data;
  dword _size;
  dword _pos;

  vector<MIDIChannelEvent*> _channelEvents;
  vector<MIDIMetaEvent*> _metaEvents;
};

#endif // MIDITRACK_H_
