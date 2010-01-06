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

/**
 * \mainpage
 * libmidi is a very simple library created for reading and writing MIDI files. It 
 * is designed to be quick to use and quick to learn.
 *
 * All interaction should be done through the MIDI::File class, which parses a MIDI file.
 * The data inside the MIDI::File class is then organized as if it were a normal MIDI file.
 * 
 * That is, MIDI::File has a header (MIDI::Header) and a list of tracks (MIDI::Track).
 *
 * Each track then has a list of MIDI events.
 *
 * See the MIDI file specification for more information.
 * http://www.midi.org/techspecs/index.php
 *
 * The following sites also describe the MIDI file, but are easier to read
 * <ul>
 *  <li>http://253.ccarh.org/handout/smf/</li>
 *  <li>http://www.piclist.com/tecHREF/io/serial/midi/midifile.html</li>
 *  <li>http://www.sonicspot.com/guide/midifiles.html</li>
 * </ul>
 */

#ifndef MIDI_H_
#define MIDI_H_

#include "Defines.h"
#include "types.h"

#include "File.h"

#include "Chunk.h"  
#include "Header.h"
#include "Track.h"

#include "Event.h"

#include "ChannelEvent.h" 
#include "ChannelControllerEvent.h"

#include "MetaEvent.h" 
#include "MetaGenericEvent.h"
#include "MetaTextEvent.h"
#include "MetaNumberEvent.h" 


#endif // MIDI_H_
