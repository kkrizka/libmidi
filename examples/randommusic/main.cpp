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

#include "MIDI.h"

#include <stdlib.h>

int main(int argc,char* argv[])
{
  MIDI::File file("output.mid");

  MIDI::Header* header=file.header();
  header->setTicksPerBeat(480);

  MIDI::Track* track=new MIDI::Track();

  MIDI::MetaGenericEvent* timeSignature=new MIDI::MetaGenericEvent(0,MIDI_METAEVENT_TIMESIGNATURE,4);
  timeSignature->setParam(0,4);
  timeSignature->setParam(1,2);
  timeSignature->setParam(2,24);
  timeSignature->setParam(3,8);

  MIDI::MetaGenericEvent* keySignature=new MIDI::MetaGenericEvent(0,MIDI_METAEVENT_KEYSIGNATURE,2);
  keySignature->setParam(0,0);
  keySignature->setParam(1,0);

  MIDI::MetaNumberEvent* tempo=new MIDI::MetaNumberEvent(0,MIDI_METAEVENT_SETTEMPO,3,900000);

  track->addEvent(timeSignature);
  track->addEvent(keySignature);
  track->addEvent(tempo);

  for(int i=0;i<128;i++)
    { 
      int note=rand()%128;
      track->addEvent(new MIDI::ChannelEvent(0,MIDI_CHEVENT_NOTEON,0,note,100));
      track->addEvent(new MIDI::ChannelEvent(100,MIDI_CHEVENT_NOTEOFF,0,note,0));
    }

  track->addEvent(new MIDI::MetaGenericEvent(25,MIDI_METAEVENT_ENDOFTRACK,0));

  file.addTrack(track);

  file.write();
}
