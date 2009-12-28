#include "MIDIHeader.h"

#include <iostream>
using namespace std;

MIDIHeader::MIDIHeader(char* data,dword size)
  : MIDIChunk(data,size),_formatType(0),_nTracks(0),_timeDivisions(0)
{
  _formatType=char2word(data);
  _nTracks=char2word(data+2);

  cout << "\tFormat Type: " << formatType() << endl;
  cout << "\tNumber of Tracks: " << nTracks() << endl;
  cout << "\tTime Division: " << timeDivisions() << endl;
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
