#include "MIDIReader.h"

#include <stdlib.h>

int main(int argc,char* argv[])
{
  MIDIFile file("output.mid");

  MIDIHeader* header=file.header();
  header->setTicksPerBeat(480);

  MIDITrack* track=new MIDITrack();

  MIDIMetaGenericEvent* timeSignature=new MIDIMetaGenericEvent(0,MIDI_METAEVENT_TIMESIGNATURE,4);
  timeSignature->setParam(0,4);
  timeSignature->setParam(1,2);
  timeSignature->setParam(2,24);
  timeSignature->setParam(3,8);

  MIDIMetaGenericEvent* keySignature=new MIDIMetaGenericEvent(0,MIDI_METAEVENT_KEYSIGNATURE,2);
  keySignature->setParam(0,0);
  keySignature->setParam(1,0);

  MIDIMetaNumberEvent* tempo=new MIDIMetaNumberEvent(0,MIDI_METAEVENT_SETTEMPO,3,900000);

  track->addEvent(timeSignature);
  track->addEvent(keySignature);
  track->addEvent(tempo);

  for(int i=0;i<128;i++)
    { 
      int note=rand()%128;
      track->addEvent(new MIDIChannelEvent(0,MIDI_CHEVENT_NOTEON,0,note,100));
      track->addEvent(new MIDIChannelEvent(100,MIDI_CHEVENT_NOTEOFF,0,note,0));
    }

  track->addEvent(new MIDIMetaGenericEvent(25,MIDI_METAEVENT_ENDOFTRACK,0));

  file.addTrack(track);

  file.write();
}
