#ifndef MIDIMETAUNKNOWNEVENT_H_
#define MIDIMETAUNKNOWNEVENT_H_

#include "MIDIMetaEvent.h"

class MIDIMetaUnknownEvent : public MIDIMetaEvent
{
public:
  MIDIMetaUnknownEvent();
  MIDIMetaUnknownEvent(const MIDIMetaUnknownEvent& o);
  MIDIMetaUnknownEvent(int deltaTime,int type,int data[],int dataLength);

  int* data();
  int dataLength();

  virtual void debug();

private:
  int* _data;
  int _dataLength;
};

#endif // MIDIMETAUNKNOWNEVENT_H_
