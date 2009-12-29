#ifndef MIDIMETAEVENT_H_
#define MIDIMETAEVENT_H_

#include "types.h"

#include "MIDIEvent.h"

class MIDIMetaEvent : public MIDIEvent
{
public:
  MIDIMetaEvent();
  MIDIMetaEvent(const MIDIMetaEvent& o);
  MIDIMetaEvent(dword deltaTime,byte metatype);

  byte metaType();

  virtual void debug();

private:
  byte _metaType;
};

#endif // MIDIMETAEVENT_H_
