#ifndef MIDIHEADER_H_
#define MIDIHEADER_H_

#include "MIDIChunk.h"

class MIDIHeader : public MIDIChunk
{
public:
  MIDIHeader(byte* data,dword size);

  int formatType();
  int nTracks();
  int timeDivisions();

private:
  int _formatType;
  int _nTracks;
  int _timeDivisions;
};

#endif // MIDIHEADER_H_
