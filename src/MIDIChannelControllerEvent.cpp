#include "MIDIChannelControllerEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIChannelControllerEvent::MIDIChannelControllerEvent()
  : MIDIChannelEvent()
{ }

MIDIChannelControllerEvent::MIDIChannelControllerEvent(const MIDIChannelControllerEvent& o)
  : MIDIChannelEvent(o),_controllertype(o._controllertype),_value(o._value)
{ }

MIDIChannelControllerEvent::MIDIChannelControllerEvent(dword deltaTime,int channel,int controllertype,int value)
  : MIDIChannelEvent(deltaTime,channel,MIDI_CHEVENT_CONTROLLER,controllertype,value),_controllertype(controllertype),_value(value)
{ }

int MIDIChannelControllerEvent::controllerType()
{
  return _controllertype;
}

int MIDIChannelControllerEvent::value()
{
  return _value;
}

void MIDIChannelControllerEvent::debug()
{
  switch(_controllertype)
    {
    case MIDI_CHEVENT_CONTROLLER_BANKSELECT:
      cout << "\tBank Select" << endl;
      break;
    case MIDI_CHEVENT_CONTROLLER_MAINVOLUME:
      cout << "\tMain Volume" << endl;
      break;
    case MIDI_CHEVENT_CONTROLLER_PAN:
      cout << "\tPan" << endl;
      break;
    case MIDI_CHEVENT_CONTROLLER_LSBCONTROLLER0:
      cout << "\tLSB For Controller 0" << endl;
      break;
    case MIDI_CHEVENT_CONTROLLER_EFFECT3DEPTH:
      cout << "\tEffect 3 Depth (Chorus Depth)" << endl;
      break;
    default:
      cout << "\tUnknown Controller Event 0x" << setbase(16) << _controllertype << endl;
      break;
    }
  cout << "\t\tValue: " << setbase(10) << _value << endl;
}
