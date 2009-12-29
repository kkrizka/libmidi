#ifndef MIDIMETAGENERICEVENT_H_
#define MIDIMETAGENERICEVENT_H_

#include "types.h"

#include "MIDIMetaEvent.h"

class MIDIMetaGenericEvent : public MIDIMetaEvent
{
public:
  MIDIMetaGenericEvent();
  MIDIMetaGenericEvent(const MIDIMetaGenericEvent& o);
  MIDIMetaGenericEvent(dword deltaTime,byte type,byte data[],int dataLength);

  byte* data();
  int dataLength();

  int paramInt(int id);
  unsigned int paramUInt(int id);

  virtual void debug();

private:
  byte* _data;
  int _dataLength;
};

#endif // MIDIMETAGENERICEVENT_H_
