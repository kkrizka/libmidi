#include "MIDI.h"

int main(int argc,char* argv[])
{
  MIDI::File file("output.mid");

  MIDI::Header* header=file.header();
  header->setTicksPerBeat(480);

  MIDI::Track* track=new MIDI::Track();

  MIDI::MetaGenericEvent* timeSignature=new MIDI::MetaGenericEvent(0,MIDI_METAEVENT_TIMESIGNATURE,4);
  timeSignature->setParam(0,4);
  timeSignature->setParam(1,2);
  timeSignature->setParam(2,24);
  timeSignature->setParam(3,8);

  MIDI::MetaGenericEvent* keySignature=new MIDI::MetaGenericEvent(0,MIDI_METAEVENT_KEYSIGNATURE,2);
  keySignature->setParam(0,0);
  keySignature->setParam(1,0);

  MIDI::MetaNumberEvent* tempo=new MIDI::MetaNumberEvent(0,MIDI_METAEVENT_SETTEMPO,3,900000);

  track->addEvent(timeSignature);
  track->addEvent(keySignature);
  track->addEvent(tempo);

  for(int i=0;i<128;i++)
    { 
      track->addEvent(new MIDI::ChannelEvent(0,MIDI_CHEVENT_NOTEON,0,i,100));
      track->addEvent(new MIDI::ChannelEvent(100,MIDI_CHEVENT_NOTEOFF,0,i,0));
    }

  for(int i=127;i>=0;i--)
    { 
      track->addEvent(new MIDI::ChannelEvent(0,MIDI_CHEVENT_NOTEON,0,i,100));
      track->addEvent(new MIDI::ChannelEvent(100,MIDI_CHEVENT_NOTEOFF,0,i,0));
    }

  track->addEvent(new MIDI::MetaGenericEvent(25,MIDI_METAEVENT_ENDOFTRACK,0));

  file.addTrack(track);

  file.write();
}
