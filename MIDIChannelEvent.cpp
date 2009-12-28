#include "MIDIChannelEvent.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIChannelEvent::MIDIChannelEvent()
  : MIDIEvent(0),_type(0),_channel(0),_param1(0),_param2(0)
{ }

MIDIChannelEvent::MIDIChannelEvent(const MIDIChannelEvent& o)
  : MIDIEvent(o),_type(o._type),_channel(o._channel),_param1(o._param1),_param2(o._param2)
{ }

MIDIChannelEvent::MIDIChannelEvent(int timeDelta,int type,int channel,int param1,int param2)
  : MIDIEvent(timeDelta),_type(type),_channel(channel),_param1(param1),_param2(param2)
{ }

int MIDIChannelEvent::type()
{
  return _type;
}

int MIDIChannelEvent::channel()
{
  return _channel;
}

int MIDIChannelEvent::param1()
{
  return _param1;
}

int MIDIChannelEvent::param2()
{
  return _param2;
}

void MIDIChannelEvent::debug()
{
  switch(_type)
    {
    case 0x0:
      cout << "\tInvalid MIDI Channel Event" << endl;
      break;
    case 0x8:
      cout << "\tEnd Note " << setbase(10) << _param1 << endl;
      cout << "\t\tVelocity: " << setbase(10) << _param2 << endl;
      break;
    case 0x9:
      cout << "\tStart Note " << setbase(10) << _param1 << endl;
      cout << "\t\tVelocity: " << setbase(10) << _param2 << endl;
      break;
    case 0xB:
      cout << "\tController Event" << endl;
      cout << "\t\tChannel: " << setbase(10) << _channel << endl;
      cout << "\t\tType: 0x" << setbase(16) << _param1 << endl;
      cout << "\t\tValue: 0x" << setbase(16) << _param2 << endl;
      break;
    case 0xC:
      cout << "\tProgram Change to " << setbase(10) << _param1 << endl;
      break;
    default:
      cout << "\tMIDI Channel Event" << endl;
      cout << "\t\tType: 0x" << setbase(16) << _type << endl;
      cout << "\t\tChannel: " << setbase(10) << _channel << endl;
      cout << "\t\tParam 1: 0x" << setbase(16) << _param1 << endl;
      cout << "\t\tParam 2: 0x" << setbase(16) << _param2 << endl;
      break;
    }

}
