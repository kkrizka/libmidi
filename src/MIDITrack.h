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

  unsigned int numEvents();
  MIDIEvent* event(unsigned int id);

private:
  dword readNextVariableLength();
  byte readNextByte();

  byte* _data;
  dword _size;
  dword _pos;

  vector<MIDIEvent*> _events;
};

#endif // MIDITRACK_H_
