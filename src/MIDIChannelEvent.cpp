#include "MIDIChannelEvent.h"

#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDIChannelEvent::MIDIChannelEvent()
  : MIDIEvent(0),_command(0),_channel(0),_param1(0),_param2(0)
{ }

MIDIChannelEvent::MIDIChannelEvent(const MIDIChannelEvent& o)
  : MIDIEvent(o),_command(o._command),_channel(o._channel),_param1(o._param1),_param2(o._param2)
{ }

MIDIChannelEvent::MIDIChannelEvent(dword timeDelta,byte command,int channel,int param1,int param2)
  : MIDIEvent(timeDelta),_command(command),_channel(channel),_param1(param1),_param2(param2)
{ }

MIDIEventType MIDIChannelEvent::type()
{
  return MIDI_CHEVENT;
}

byte MIDIChannelEvent::command()
{
  return _command;
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

MIDIDataBuffer MIDIChannelEvent::data(bool shorten)
{
  MIDIDataBuffer data=MIDIEvent::data();

  if(!shorten)
    {
      byte typething=_command;
      typething=(typething<<4);
      typething+=_channel;
      data.write(typething);
    }
  data.write(_param1);
  data.write(_param2);

  return data;
}

void MIDIChannelEvent::debug()
{
  switch(_command)
    {
    case MIDI_CHEVENT_INVALID:
      cout << "\tInvalid MIDI Channel Event" << endl;
      break;
    case MIDI_CHEVENT_NOTEOFF:
      cout << "\tEnd Note " << setbase(10) << _param1 << endl;
      cout << "\t\tVelocity: " << setbase(10) << _param2 << endl;
      break;
    case MIDI_CHEVENT_NOTEON:
      cout << "\tStart Note " << setbase(10) << _param1 << endl;
      cout << "\t\tVelocity: " << setbase(10) << _param2 << endl;
      break;
    case MIDI_CHEVENT_NOTEAFTERTOUCH:
      cout << "\tNote Aftertouch" << setbase(10) << _param1 << endl;
      cout << "\t\tValue: " << setbase(10) << _param2 << endl;
      break;
    case MIDI_CHEVENT_CONTROLLER:
      cout << "\tController Event" << endl;
      cout << "\t\tChannel: " << setbase(10) << _channel << endl;
      cout << "\t\tType: 0x" << setbase(16) << _param1 << endl;
      cout << "\t\tValue: 0x" << setbase(16) << _param2 << endl;
      break;
    case MIDI_CHEVENT_PROGRAMCHANGE:
      cout << "\tProgram Change to " << setbase(10) << _param1 << endl;
      break;
    case MIDI_CHEVENT_CHANNELAFTERTOUCH:
      cout << "\tChannel Aftertouch" << endl;
      cout << "\t\tValue: " << setbase(10) << _param1 << endl;
      break;
    case MIDI_CHEVENT_PITCHBEND:
      cout << "\tPitch Bend" << endl;
      cout << "\t\tPitch Value (MSB): " << setbase(10) << _param1 << endl;
      cout << "\t\tPitch Value (LSB): " << setbase(10) << _param2 << endl;
      break;
    default:
      cout << "\tUnknown MIDI Channel Event" << endl;
      cout << "\t\tCommand: 0x" << setbase(16) << (unsigned int)_command << endl;
      cout << "\t\tChannel: " << setbase(10) << _channel << endl;
      cout << "\t\tParam 1: 0x" << setbase(16) << _param1 << endl;
      cout << "\t\tParam 2: 0x" << setbase(16) << _param2 << endl;
      break;
    }

}
