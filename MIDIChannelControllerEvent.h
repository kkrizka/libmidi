#ifndef MIDICHANNELCONTROLLEREVENT_H_
#define MIDICHANNELCONTROLLEREVENT_H_

#include "MIDIChannelEvent.h"

class MIDIChannelControllerEvent : public MIDIChannelEvent
{
public:
  MIDIChannelControllerEvent();
  MIDIChannelControllerEvent(const MIDIChannelControllerEvent& o);
  MIDIChannelControllerEvent(int deltaTime,int channel,int controllertype,int value);

  int controllerType();
  int value();

  virtual void debug();

private:
  int _controllertype;
  int _value;
};

#endif // MIDICHANNELCONTROLLEREVENT_H_
