#include "MIDIMetaUnknownEvent.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIMetaUnknownEvent::MIDIMetaUnknownEvent()
  : MIDIMetaEvent(),_data(0),_dataLength(0)
{ }

MIDIMetaUnknownEvent::MIDIMetaUnknownEvent(const MIDIMetaUnknownEvent& o)
  : MIDIMetaEvent(o),_data(o._data),_dataLength(o._dataLength)
{ }

MIDIMetaUnknownEvent::MIDIMetaUnknownEvent(int deltaTime,int metaType,int data[],int dataLength)
  : MIDIMetaEvent(deltaTime,metaType),_data(data),_dataLength(dataLength)
{ }

int* MIDIMetaUnknownEvent::data()
{
  return _data;
}

int MIDIMetaUnknownEvent::dataLength()
{
  return _dataLength;
}

void MIDIMetaUnknownEvent::debug()
{
  cout << "\tUnknown Meta Event 0x" << setbase(16) << metaType() << endl;
}
