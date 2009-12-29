#ifndef MIDIEVENT_H_
#define MIDIEVENT_H_

class MIDIEvent
{
public:
  MIDIEvent();
  MIDIEvent(const MIDIEvent& o);
  MIDIEvent(int deltaTime);

  int deltaTime();

  virtual void debug();

private:
  int _deltaTime;
};

#endif // MIDIEVENT_H_
