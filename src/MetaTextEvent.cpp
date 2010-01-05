#include "MetaTextEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  MetaTextEvent::MetaTextEvent()
    : MetaEvent()
  { }
  
  MetaTextEvent::MetaTextEvent(const MetaTextEvent& o)
    : MetaEvent(o),_text(o._text)
  { }
  
  MetaTextEvent::MetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length)
    : MetaEvent(deltaTime,metaType)
  { 
    _text="";
    for(int i=0;i<length;i++)
      {
	_text+=((char)data[i]);
      }
  }
  
  string MetaTextEvent::text()
  {
    return _text;
  }
  
  DataBuffer MetaTextEvent::data()
  {
    DataBuffer data=MetaEvent::data();
    
    data.writeVariableLength(_text.length());
    for(int i=0;i<_text.length();i++)
      {
	data.write(_text[i]);
      }
    
    return data;
  }
  
  void MetaTextEvent::debug()
  {
    switch(metaType())
      {
      case MIDI_METAEVENT_TEXT:
	cout << "\tText" << endl;
	cout << "\t\t" << _text;
	break;
      case MIDI_METAEVENT_COPYRIGHT:
	cout << "\tCopyright" << endl;
	cout << "\t\t" << _text << endl;
	break;
      case MIDI_METAEVENT_TRACKNAME:
	cout << "\tTrack Name: " << _text << endl;
	break;
      case MIDI_METAEVENT_MAKER:
	cout << "\tMaker: " << _text << endl;
	break;
      default:
	cout << "\tUnknown Meta Text Event 0x" << setbase(16) << (unsigned int)metaType() << endl;
	cout << "\t\t" << _text;
	break;
      }
  }
}
