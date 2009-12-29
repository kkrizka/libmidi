#include "MIDIHeader.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIHeader::MIDIHeader(byte* data,dword size)
  : MIDIChunk(data,size),_formatType(0),_nTracks(0),_timeDivisions(0)
{
  _formatType=byte2word(data);
  _nTracks=byte2word(data+2);

}

int MIDIHeader::nTracks()
{
  return _nTracks;
}

int MIDIHeader::formatType()
{
  return _formatType;
}

int MIDIHeader::timeDivisions()
{
  #warning "MIDIHeader::timeDivisions() is unimplemented"
  return _timeDivisions;
}
