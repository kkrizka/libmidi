#include "MIDIMetaNumberEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIMetaNumberEvent::MIDIMetaNumberEvent()
  : MIDIMetaEvent()
{ }

MIDIMetaNumberEvent::MIDIMetaNumberEvent(const MIDIMetaNumberEvent& o)
  : MIDIMetaEvent(o),_number(o._number)
{ }

MIDIMetaNumberEvent::MIDIMetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length)
  : MIDIMetaEvent(deltaTime,metaType),_number(0)
{ 
  for(int i=0;i<length;i++)
    {
      _number=(_number<<8);
      _number+=(unsigned int)data[i];
    }
}

unsigned int MIDIMetaNumberEvent::number()
{
  return _number;
}

void MIDIMetaNumberEvent::debug()
{
  switch(metaType())
    {
    case MIDI_METAEVENT_SETTEMPO:
      cout << "\tSet Tempo" << endl;
      cout << "\t\tMicroseconds/Quarter-note: " << number() << endl;
    default:
      cout << "\tUnknown Meta Number Event 0x" << setbase(16) << (unsigned int)metaType() << endl;
      cout << "\t\t" << _number;
      break;
    }
}
