/*
  Copyright (C) 2010 Karol Krizka <kkrizka@gmail.com>
  
  URL: http://www.krizka.net/projects/libmidi/
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  $Id$
*/

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
