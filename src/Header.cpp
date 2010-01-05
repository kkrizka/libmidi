#include "Header.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  Header::Header()
    : Chunk(),_formatType(0),_numTracks(0),_timeDivisions(0)
  { }
  
  
  Header::Header(byte* data,dword size)
    : Chunk(),_formatType(0),_numTracks(0),_timeDivisions(0)
  {
    _formatType=byte2word(data);
    _numTracks=byte2word(data+2);
    _timeDivisions=byte2word(data+4);
  }
  
  unsigned int Header::numTracks()
  {
    return _numTracks;
  }
  
  void Header::setNumTracks(unsigned int numTracks)
  {
    _numTracks=numTracks;
  }
  
  int Header::formatType()
  {
    return _formatType;
  }
  
  int Header::timeDivisions()
  {
    return _timeDivisions;
  }
  
  unsigned int Header::ticksPerBeat()
  {
    if( 0x8000 & _timeDivisions ) return 0;
    
    return (0x7FFF & _timeDivisions);
  }
  
  void Header::setTicksPerBeat(unsigned int ticksPerBeat)
  {
    _timeDivisions=ticksPerBeat;
  }
  
  unsigned int Header::framesPerSecond()
  {
    if( !(0x8000 & _timeDivisions) ) return 0;
    
    return (0x7F00 & _timeDivisions)>>8;
  }
  
  void Header::setFramesPerSecond(unsigned int framesPerSecond)
  {
    _timeDivisions=( 0x8000 | (framesPerSecond<<8) | (0x00FF & _timeDivisions) );
  }
  
  unsigned int Header::ticksPerFrame()
  {
    if( !(0x8000 & _timeDivisions) ) return 0;
    
    return (0x00FF & _timeDivisions);
  }
  
  void Header::setTicksPerFrame(unsigned int ticksPerFrame)
  {
    _timeDivisions=( 0x8000 | ticksPerFrame | (0x7F00 & _timeDivisions) );
  }
  
  
  DataBuffer Header::data()
  {
    DataBuffer data(6);
    
    data.write(word2byte(_formatType),2);
    data.write(word2byte(_numTracks),2);
    data.write(word2byte(_timeDivisions),2);
    
    return data;
  }
}
