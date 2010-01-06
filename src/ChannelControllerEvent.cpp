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

#include "ChannelControllerEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  ChannelControllerEvent::ChannelControllerEvent()
    : ChannelEvent()
  { }
  
  ChannelControllerEvent::ChannelControllerEvent(const ChannelControllerEvent& o)
    : ChannelEvent(o),_controllertype(o._controllertype),_value(o._value)
  { }
  
  ChannelControllerEvent::ChannelControllerEvent(dword deltaTime,int channel,int controllertype,int value)
    : ChannelEvent(deltaTime,MIDI_CHEVENT_CONTROLLER,channel,controllertype,value),_controllertype(controllertype),_value(value)
  { }
  
  int ChannelControllerEvent::controllerType()
  {
    return _controllertype;
  }
  
  int ChannelControllerEvent::value()
  {
    return _value;
  }
  
  void ChannelControllerEvent::debug()
  {
    switch(_controllertype)
      {
      case MIDI_CHEVENT_CONTROLLER_BANKSELECT:
	cout << "\tBank Select" << endl;
	break;
      case MIDI_CHEVENT_CONTROLLER_MAINVOLUME:
	cout << "\tMain Volume" << endl;
	break;
      case MIDI_CHEVENT_CONTROLLER_PAN:
	cout << "\tPan" << endl;
	break;
      case MIDI_CHEVENT_CONTROLLER_LSBCONTROLLER0:
	cout << "\tLSB For Controller 0" << endl;
	break;
      case MIDI_CHEVENT_CONTROLLER_EFFECT3DEPTH:
	cout << "\tEffect 3 Depth (Chorus Depth)" << endl;
	break;
      default:
	cout << "\tUnknown Controller Event 0x" << setbase(16) << _controllertype << endl;
	break;
      }
    cout << "\t\tValue: " << setbase(10) << _value << endl;
  }
}
