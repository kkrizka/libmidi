#include "MetaEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  MetaEvent::MetaEvent()
    : Event(),_metaType(MIDI_METAEVENT_INVALID)
  { }
  
  MetaEvent::MetaEvent(const MetaEvent& o)
    : Event(o),_metaType(o._metaType)
  { }
  
  MetaEvent::MetaEvent(dword deltaTime,byte metaType)
    : Event(deltaTime),_metaType(metaType)
  { }
  
  EventType MetaEvent::type()
  {
    return MIDI_METAEVENT;
  }
  
  byte MetaEvent::metaType()
  { 
    return _metaType;
  }
  
  DataBuffer MetaEvent::data()
  {
    DataBuffer data=Event::data();
    
    data.write(0xFF);
    data.write(metaType());
    
    return data;
  }
  
  void MetaEvent::debug()
  { 
    cout << "\tInvalid Meta Event 0x" << setbase(16) << (unsigned int)_metaType << endl;
  }
}
