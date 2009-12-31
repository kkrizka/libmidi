#include "MIDIMetaNumberEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIMetaNumberEvent::MIDIMetaNumberEvent()
  : MIDIMetaEvent(),_number(0),_length(0)
{ }

MIDIMetaNumberEvent::MIDIMetaNumberEvent(const MIDIMetaNumberEvent& o)
  : MIDIMetaEvent(o),_number(o._number),_length(o._length)
{ }

MIDIMetaNumberEvent::MIDIMetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length)
  : MIDIMetaEvent(deltaTime,metaType),_number(0),_length(length)
{ 
  for(int i=0;i<_length;i++)
    {
      _number=(_number<<8);
      _number+=(unsigned int)data[i];
    }
}

unsigned int MIDIMetaNumberEvent::number()
{
  return _number;
}

MIDIDataBuffer MIDIMetaNumberEvent::data()
{
  MIDIDataBuffer data=MIDIMetaEvent::data();
 
  // Calculate number of needed bytes
  unsigned int num=_number;

  data.write(_length);

  byte bytedata[_length];
  for(int i=0;i<_length;i++)
    {
      bytedata[_length-1-i]=(num & 0xFF);
      num=(num>>8);
    }
  
  data.write(bytedata,_length);

  return data;
}

void MIDIMetaNumberEvent::debug()
{
  switch(metaType())
    {
    case MIDI_METAEVENT_SETTEMPO:
      cout << "\tSet Tempo" << endl;
      cout << "\t\tMicroseconds/Quarter-note: " << number() << endl;
      break;
    default:
      cout << "\tUnknown Meta Number Event 0x" << setbase(16) << (unsigned int)metaType() << endl;
      cout << "\t\t" << _number << endl;
      break;
    }
}
