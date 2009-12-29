#include "MIDIMetaEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIMetaEvent::MIDIMetaEvent()
  : MIDIEvent(),_metaType(MIDI_METAEVENT_INVALID)
{ }

MIDIMetaEvent::MIDIMetaEvent(const MIDIMetaEvent& o)
  : MIDIEvent(o),_metaType(o._metaType)
{ }

MIDIMetaEvent::MIDIMetaEvent(dword deltaTime,byte metaType)
  : MIDIEvent(deltaTime),_metaType(metaType)
{ }

byte MIDIMetaEvent::metaType()
{ 
  return _metaType;
}

void MIDIMetaEvent::debug()
{ 
  cout << "\tInvalid Meta Event 0x" << setbase(16) << (unsigned int)_metaType << endl;
}
