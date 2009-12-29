#include "MIDIMetaTextEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIMetaTextEvent::MIDIMetaTextEvent()
  : MIDIMetaEvent()
{ }

MIDIMetaTextEvent::MIDIMetaTextEvent(const MIDIMetaTextEvent& o)
  : MIDIMetaEvent(o),_text(o._text)
{ }

MIDIMetaTextEvent::MIDIMetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length)
  : MIDIMetaEvent(deltaTime,metaType)
{ 
  _text="";
  for(int i=0;i<length;i++)
    {
      _text+=((char)data[i]);
    }
}

string MIDIMetaTextEvent::text()
{
  return _text;
}

void MIDIMetaTextEvent::debug()
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
