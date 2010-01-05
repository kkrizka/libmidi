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
