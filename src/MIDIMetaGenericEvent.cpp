#include "MIDIMetaGenericEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIMetaGenericEvent::MIDIMetaGenericEvent()
  : MIDIMetaEvent(),_data(0),_dataLength(0)
{ }

MIDIMetaGenericEvent::MIDIMetaGenericEvent(const MIDIMetaGenericEvent& o)
  : MIDIMetaEvent(o),_data(0),_dataLength(o._dataLength)
{
  _data=new byte[_dataLength];
  for(int i=0;i<_dataLength;i++)
    {
      _data[i]=o._data[i];
    }
}

MIDIMetaGenericEvent::MIDIMetaGenericEvent(dword deltaTime,byte metaType,byte data[],int dataLength)
  : MIDIMetaEvent(deltaTime,metaType),_data(0),_dataLength(dataLength)
{
  _data=new byte[_dataLength];
  for(int i=0;i<_dataLength;i++)
    {
      _data[i]=data[i];
    }
}

MIDIMetaGenericEvent::MIDIMetaGenericEvent(dword deltaTime,byte metaType,int dataLength)
  : MIDIMetaEvent(deltaTime,metaType),_data(0),_dataLength(dataLength)
{
  _data=new byte[_dataLength];
  for(int i=0;i<_dataLength;i++)
    {
      _data[i]='\0';
    }
}

int MIDIMetaGenericEvent::dataLength()
{
  return _dataLength;
}

int MIDIMetaGenericEvent::paramInt(unsigned int id)
{
  return (int)_data[id];
}

unsigned int MIDIMetaGenericEvent::paramUInt(unsigned int id)
{  
  return char2num((char)_data[id]);
}

void MIDIMetaGenericEvent::setParam(unsigned int id,byte value)
{
  _data[id]=value;
}

MIDIDataBuffer MIDIMetaGenericEvent::data()
{
  MIDIDataBuffer data=MIDIMetaEvent::data();

  data.writeVariableLength(_dataLength);
  for(int i=0;i<_dataLength;i++)
    {
      data.write(_data[i]);
    }

  return data;
}

void MIDIMetaGenericEvent::debug()
{
  switch(metaType())
    {
    case MIDI_METAEVENT_PORT:
      cout << "\tMIDI Port" << endl;
      cout << "\t\tPort: " << paramUInt(0) << endl;
      break;
    case MIDI_METAEVENT_TIMESIGNATURE:
      cout << "\tTime Signature" << endl;
      cout << "\t\tNumerator: " << paramUInt(0) << endl;
      cout << "\t\tDenominator: " << paramUInt(1) << endl;
      cout << "\t\tMetronome: " << paramUInt(2) << endl;
      cout << "\t\t32nds: " << paramUInt(3) << endl;
      break;
    case MIDI_METAEVENT_KEYSIGNATURE:
      cout << "\tKey Signature" << endl;
      cout << "\t\tKey: " << paramInt(0) << endl;
      cout << "\t\tScale: " << paramUInt(1) << endl;
      break;
    case MIDI_METAEVENT_ENDOFTRACK:
      cout << "\tEnd of Track" << endl;
      break;
    default:
      cout << "\tGeneric Meta Event 0x" << setbase(16) << (unsigned int)metaType() << endl;
      for(int i=0;i<_dataLength;i++)
	{
	  cout << "\t\t0x" << setbase(16) << paramInt(i) << endl;
	}
      break;
    }
}
