#include "MIDIHeader.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIHeader::MIDIHeader()
  : MIDIChunk(),_formatType(0),_numTracks(0),_timeDivisions(0)
{ }


MIDIHeader::MIDIHeader(byte* data,dword size)
  : MIDIChunk(),_formatType(0),_numTracks(0),_timeDivisions(0)
{
  _formatType=byte2word(data);
  _numTracks=byte2word(data+2);
  _timeDivisions=byte2word(data+4);
}

int MIDIHeader::numTracks()
{
  return _numTracks;
}

int MIDIHeader::formatType()
{
  return _formatType;
}

int MIDIHeader::timeDivisions()
{
  return _timeDivisions;
}

unsigned int MIDIHeader::ticksPerBeat()
{
  if( 0x8000 & _timeDivisions ) return 0;
  
  return (0x7FFF & _timeDivisions);
}

unsigned int MIDIHeader::framesPerSecond()
{
  if( !(0x8000 & _timeDivisions) ) return 0;
  
  return (0x7F00 & _timeDivisions);
}

unsigned int MIDIHeader::ticksPerFrame()
{
  if( !(0x8000 & _timeDivisions) ) return 0;
  
  return (0x00FF & _timeDivisions);
}

MIDIDataBuffer MIDIHeader::data()
{
  MIDIDataBuffer data(6);

  data.write(word2byte(_formatType),2);
  data.write(word2byte(_numTracks),2);
  data.write(word2byte(_timeDivisions),2);

  return data;
}
