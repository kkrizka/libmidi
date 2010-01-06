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

#include "MetaTextEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  MetaTextEvent::MetaTextEvent()
    : MetaEvent()
  { }
  
  MetaTextEvent::MetaTextEvent(const MetaTextEvent& o)
    : MetaEvent(o),_text(o._text)
  { }
  
  MetaTextEvent::MetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length)
    : MetaEvent(deltaTime,metaType)
  { 
    _text="";
    for(int i=0;i<length;i++)
      {
	_text+=((char)data[i]);
      }
  }
  
  string MetaTextEvent::text()
  {
    return _text;
  }
  
  DataBuffer MetaTextEvent::data()
  {
    DataBuffer data=MetaEvent::data();
    
    data.writeVariableLength(_text.length());
    for(int i=0;i<_text.length();i++)
      {
	data.write(_text[i]);
      }
    
    return data;
  }
  
  void MetaTextEvent::debug()
  {
    switch(metaType())
      {
      case MIDI_METAEVENT_TEXT:
	cout << "\tText" << endl;
	cout << "\t\t" << _text;
	break;
      case MIDI_METAEVENT_COPYRIGHT:
	cout << "\tCopyright" << endl;
	cout << "\t\t" << _text << endl;
	break;
      case MIDI_METAEVENT_TRACKNAME:
	cout << "\tTrack Name: " << _text << endl;
	break;
      case MIDI_METAEVENT_MAKER:
	cout << "\tMaker: " << _text << endl;
	break;
      default:
	cout << "\tUnknown Meta Text Event 0x" << setbase(16) << (unsigned int)metaType() << endl;
	cout << "\t\t" << _text;
	break;
      }
  }
}
