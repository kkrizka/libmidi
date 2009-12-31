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

unsigned int MIDIHeader::numTracks()
{
  return _numTracks;
}

void MIDIHeader::setNumTracks(unsigned int numTracks)
{
  _numTracks=numTracks;
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

void MIDIHeader::setTicksPerBeat(unsigned int ticksPerBeat)
{
  _timeDivisions=ticksPerBeat;
}

unsigned int MIDIHeader::framesPerSecond()
{
  if( !(0x8000 & _timeDivisions) ) return 0;
  
  return (0x7F00 & _timeDivisions)>>8;
}

void MIDIHeader::setFramesPerSecond(unsigned int framesPerSecond)
{
  _timeDivisions=( 0x8000 | (framesPerSecond<<8) | (0x00FF & _timeDivisions) );
}

unsigned int MIDIHeader::ticksPerFrame()
{
  if( !(0x8000 & _timeDivisions) ) return 0;
  
  return (0x00FF & _timeDivisions);
}

void MIDIHeader::setTicksPerFrame(unsigned int ticksPerFrame)
{
  _timeDivisions=( 0x8000 | ticksPerFrame | (0x7F00 & _timeDivisions) );
}


MIDIDataBuffer MIDIHeader::data()
{
  MIDIDataBuffer data(6);

  data.write(word2byte(_formatType),2);
  data.write(word2byte(_numTracks),2);
  data.write(word2byte(_timeDivisions),2);

  return data;
}
