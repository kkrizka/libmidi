#ifndef MIDICHANNELEVENT_H_
#define MIDICHANNELEVENT_H_

#include "MIDIEvent.h"

class MIDIChannelEvent : public MIDIEvent
{
public:
  MIDIChannelEvent();
  MIDIChannelEvent(const MIDIChannelEvent& o);
  MIDIChannelEvent(int timeDelta,int type,int channel,int param1,int param2);

  int type();
  int channel();
  int param1();
  int param2();

  virtual void debug();

private:
  int _type;
  int _channel;
  int _param1;
  int _param2;
};

#endif // MIDICHANNELEVENT_H_
