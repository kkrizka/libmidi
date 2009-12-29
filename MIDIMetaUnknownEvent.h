#ifndef MIDIMETAUNKNOWNEVENT_H_
#define MIDIMETAUNKNOWNEVENT_H_

#include "types.h"

#include "MIDIMetaEvent.h"

class MIDIMetaUnknownEvent : public MIDIMetaEvent
{
public:
  MIDIMetaUnknownEvent();
  MIDIMetaUnknownEvent(const MIDIMetaUnknownEvent& o);
  MIDIMetaUnknownEvent(dword deltaTime,byte type,byte data[],int dataLength);

  byte* data();
  int dataLength();

  virtual void debug();

private:
  byte* _data;
  int _dataLength;
};

#endif // MIDIMETAUNKNOWNEVENT_H_
