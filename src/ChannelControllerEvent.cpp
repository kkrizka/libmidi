#include "ChannelControllerEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  ChannelControllerEvent::ChannelControllerEvent()
    : ChannelEvent()
  { }
  
  ChannelControllerEvent::ChannelControllerEvent(const ChannelControllerEvent& o)
    : ChannelEvent(o),_controllertype(o._controllertype),_value(o._value)
  { }
  
  ChannelControllerEvent::ChannelControllerEvent(dword deltaTime,int channel,int controllertype,int value)
    : ChannelEvent(deltaTime,MIDI_CHEVENT_CONTROLLER,channel,controllertype,value),_controllertype(controllertype),_value(value)
  { }
  
  int ChannelControllerEvent::controllerType()
  {
    return _controllertype;
  }
  
  int ChannelControllerEvent::value()
  {
    return _value;
  }
  
  void ChannelControllerEvent::debug()
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
}
