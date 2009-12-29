#ifndef MIDIMETAEVENT_H_
#define MIDIMETAEVENT_H_

#include "MIDIEvent.h"

class MIDIMetaEvent : public MIDIEvent
{
public:
  MIDIMetaEvent();
  MIDIMetaEvent(const MIDIMetaEvent& o);
  MIDIMetaEvent(int deltaTime,int metatype);

  int metaType();

  virtual void debug();

private:
  int _metaType;
};

#endif // MIDIMETAEVENT_H_
