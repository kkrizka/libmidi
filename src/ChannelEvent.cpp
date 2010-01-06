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

#include "ChannelEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  ChannelEvent::ChannelEvent()
    : Event(0),_command(0),_channel(0),_param1(0),_param2(0)
  { }
  
  ChannelEvent::ChannelEvent(const ChannelEvent& o)
    : Event(o),_command(o._command),_channel(o._channel),_param1(o._param1),_param2(o._param2)
  { }
  
  ChannelEvent::ChannelEvent(dword timeDelta,byte command,int channel,int param1,int param2)
    : Event(timeDelta),_command(command),_channel(channel),_param1(param1),_param2(param2)
  { }
  
  EventType ChannelEvent::type()
  {
    return MIDI_CHEVENT;
  }
  
  byte ChannelEvent::command()
  {
    return _command;
  }
  
  int ChannelEvent::channel()
  {
    return _channel;
  }
  
  int ChannelEvent::param1()
  {
    return _param1;
  }
  
  int ChannelEvent::param2()
  {
    return _param2;
  }
  
  DataBuffer ChannelEvent::data(bool shorten)
  {
    DataBuffer data=Event::data();
    
    if(!shorten)
      {
	byte typething=_command;
	typething=(typething<<4);
	typething+=_channel;
	data.write(typething);
      }
    data.write(_param1);
    data.write(_param2);
    
    return data;
  }
  
  void ChannelEvent::debug()
  {
    switch(_command)
      {
      case MIDI_CHEVENT_INVALID:
	cout << "\tInvalid MIDI Channel Event" << endl;
	break;
      case MIDI_CHEVENT_NOTEOFF:
	cout << "\tEnd Note " << setbase(10) << _param1 << endl;
	cout << "\t\tVelocity: " << setbase(10) << _param2 << endl;
	break;
      case MIDI_CHEVENT_NOTEON:
	cout << "\tStart Note " << setbase(10) << _param1 << endl;
	cout << "\t\tVelocity: " << setbase(10) << _param2 << endl;
	break;
      case MIDI_CHEVENT_NOTEAFTERTOUCH:
	cout << "\tNote Aftertouch" << setbase(10) << _param1 << endl;
	cout << "\t\tValue: " << setbase(10) << _param2 << endl;
	break;
      case MIDI_CHEVENT_CONTROLLER:
	cout << "\tController Event" << endl;
	cout << "\t\tChannel: " << setbase(10) << _channel << endl;
	cout << "\t\tType: 0x" << setbase(16) << _param1 << endl;
	cout << "\t\tValue: 0x" << setbase(16) << _param2 << endl;
	break;
      case MIDI_CHEVENT_PROGRAMCHANGE:
	cout << "\tProgram Change to " << setbase(10) << _param1 << endl;
	break;
      case MIDI_CHEVENT_CHANNELAFTERTOUCH:
	cout << "\tChannel Aftertouch" << endl;
	cout << "\t\tValue: " << setbase(10) << _param1 << endl;
	break;
      case MIDI_CHEVENT_PITCHBEND:
	cout << "\tPitch Bend" << endl;
	cout << "\t\tPitch Value (MSB): " << setbase(10) << _param1 << endl;
	cout << "\t\tPitch Value (LSB): " << setbase(10) << _param2 << endl;
	break;
      default:
	cout << "\tUnknown MIDI Channel Event" << endl;
	cout << "\t\tCommand: 0x" << setbase(16) << (unsigned int)_command << endl;
	cout << "\t\tChannel: " << setbase(10) << _channel << endl;
	cout << "\t\tParam 1: 0x" << setbase(16) << _param1 << endl;
	cout << "\t\tParam 2: 0x" << setbase(16) << _param2 << endl;
	break;
      }   
  }
}
