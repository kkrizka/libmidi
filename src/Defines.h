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

#ifndef MIDIDEFINES_H_
#define MIDIDEFINES_H_

namespace MIDI
{
  enum EventType
  {
    MIDI_METAEVENT,
    MIDI_CHEVENT,
    MIDI_SYSEXEVENT
  };
}

// Meta event types
#define MIDI_METAEVENT_INVALID 0x0
#define MIDI_METAEVENT_TEXT 0x1
#define MIDI_METAEVENT_COPYRIGHT 0x2
#define MIDI_METAEVENT_TRACKNAME 0x3
#define MIDI_METAEVENT_MAKER 0x6
#define MIDI_METAEVENT_SETTEMPO 0x51
#define MIDI_METAEVENT_PORT 0x21
#define MIDI_METAEVENT_TIMESIGNATURE 0x58
#define MIDI_METAEVENT_KEYSIGNATURE 0x59
#define MIDI_METAEVENT_ENDOFTRACK 0x2F

// Channel event types
#define MIDI_CHEVENT_INVALID 0x0
#define MIDI_CHEVENT_NOTEOFF 0x8
#define MIDI_CHEVENT_NOTEON 0x9
#define MIDI_CHEVENT_NOTEAFTERTOUCH 0xA
#define MIDI_CHEVENT_CONTROLLER 0xB
#define MIDI_CHEVENT_PROGRAMCHANGE 0xC
#define MIDI_CHEVENT_CHANNELAFTERTOUCH 0xD
#define MIDI_CHEVENT_PITCHBEND 0xE

// Channel controller types
#define MIDI_CHEVENT_CONTROLLER_BANKSELECT 0x0
#define MIDI_CHEVENT_CONTROLLER_MAINVOLUME 0x7
#define MIDI_CHEVENT_CONTROLLER_PAN 0xA
#define MIDI_CHEVENT_CONTROLLER_LSBCONTROLLER0 0x20
#define MIDI_CHEVENT_CONTROLLER_EFFECT3DEPTH 0x5D

#endif // MIDIDEFINES_H_
