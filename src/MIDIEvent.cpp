#include "MIDIEvent.h"

#include <iostream>
using namespace std;

MIDIEvent::MIDIEvent()
  : _deltaTime(0)
{ }

MIDIEvent::MIDIEvent(const MIDIEvent& o)
  : _deltaTime(o._deltaTime)
{ }

MIDIEvent::MIDIEvent(dword deltaTime)
  : _deltaTime(deltaTime)
{ }

dword MIDIEvent::deltaTime()
{
  return _deltaTime;
}

MIDIDataBuffer MIDIEvent::data()
{
  MIDIDataBuffer data(10000);
  data.writeVariableLength(_deltaTime);
  return data;
}

void MIDIEvent::debug()
{
  cout << "\tMIDI Event" << endl;
}
