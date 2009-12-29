#ifndef MIDIMETATEXTEVENT_H_
#define MIDIMETATEXTEVENT_H_

#include "MIDIMetaEvent.h"

#include <string>
using namespace std;

class MIDIMetaTextEvent : public MIDIMetaEvent
{
public:
  MIDIMetaTextEvent();
  MIDIMetaTextEvent(const MIDIMetaTextEvent& o);
  MIDIMetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length);

  string text();

  virtual void debug();

private:
  string _text;
};

#endif //MIDIMETATEXTEVENT_H_
