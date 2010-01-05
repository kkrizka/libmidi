#include "Event.h"

#include <iostream>
using namespace std;

namespace MIDI
{
  Event::Event()
    : _deltaTime(0)
  { }
  
  Event::Event(const Event& o)
    : _deltaTime(o._deltaTime)
  { }
  
  Event::Event(dword deltaTime)
    : _deltaTime(deltaTime)
  { }
  
  dword Event::deltaTime()
  {
    return _deltaTime;
  }
  
  DataBuffer Event::data()
  {
    DataBuffer data(10000);
    data.writeVariableLength(_deltaTime);
    return data;
  }
  
  void Event::debug()
  {
    cout << "\tMIDI Event" << endl;
  }
}
