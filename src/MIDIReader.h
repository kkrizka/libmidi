/**
 * \mainpage
 * libmidireader is a very simple library created for reading MIDI files. It is designed
 * to be quick to use and quick to learn.
 *
 * All interaction should be done through the MIDIFile class, which parses a MIDI file.
 * The data inside the MIDIFile class is then organized as if it were a normal MIDI file.
 * 
 * That is, MIDIFile has a header (MIDIHeader) and a list of tracks (MIDITrack).
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

#ifndef MIDIREADER_H_
#define MIDIREADER_H_

#include "MIDIDefines.h"
#include "types.h"

#include "MIDIFile.h"

#include "MIDIChunk.h"  
#include "MIDIHeader.h"
#include "MIDITrack.h"

#include "MIDIEvent.h"

#include "MIDIChannelEvent.h" 
#include "MIDIChannelControllerEvent.h"

#include "MIDIMetaEvent.h" 
#include "MIDIMetaGenericEvent.h"
#include "MIDIMetaTextEvent.h"
#include "MIDIMetaNumberEvent.h" 


#endif // MIDIREADER_H_
