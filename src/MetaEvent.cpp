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

#include "MetaEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  MetaEvent::MetaEvent()
    : Event(),_metaType(MIDI_METAEVENT_INVALID)
  { }
  
  MetaEvent::MetaEvent(const MetaEvent& o)
    : Event(o),_metaType(o._metaType)
  { }
  
  MetaEvent::MetaEvent(dword deltaTime,byte metaType)
    : Event(deltaTime),_metaType(metaType)
  { }
  
  EventType MetaEvent::type()
  {
    return MIDI_METAEVENT;
  }
  
  byte MetaEvent::metaType()
  { 
    return _metaType;
  }
  
  DataBuffer MetaEvent::data()
  {
    DataBuffer data=Event::data();
    
    data.write(0xFF);
    data.write(metaType());
    
    return data;
  }
  
  void MetaEvent::debug()
  { 
    cout << "\tInvalid Meta Event 0x" << setbase(16) << (unsigned int)_metaType << endl;
  }
}
