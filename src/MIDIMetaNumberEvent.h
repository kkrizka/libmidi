#ifndef MIDIMETANUMBEREVENT_H_
#define MIDIMETANUMBEREVENT_H_

#include "MIDIMetaEvent.h"

class MIDIMetaNumberEvent : public MIDIMetaEvent
{
public:
  MIDIMetaNumberEvent();
  MIDIMetaNumberEvent(const MIDIMetaNumberEvent& o);
  MIDIMetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length);

  unsigned int number();

  virtual void debug();

private:
  unsigned int _number;
};

#endif //MIDIMETANUMBEREVENT_H_
