#include "MIDITrack.h"

#include "MIDIChannelControllerEvent.h"
#include "MIDIMetaGenericEvent.h"
#include "MIDIMetaTextEvent.h"
#include "MIDIMetaNumberEvent.h"
#include "MIDIDefines.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDITrack::MIDITrack()
{ }

MIDITrack::MIDITrack(byte* data,dword size)
  : _data(data),_size(size),_pos(0)
{
  byte lastMIDICommand;
  int lastChannel;

  while(_pos<_size)
    {
      dword deltaTime=readNextVariableLength();
      byte eventType=readNextByte();
      
      switch(eventType)
	{
	case 0xFF: //Meta event
	  {
	    byte type=readNextByte();
	    dword length=readNextVariableLength();
	    byte metaData[length];
	    for(int i=0;i<length;i++)
	      {
		metaData[i]=readNextByte();
	      }

	    MIDIMetaEvent *event;
	    switch(type)
	      {
	      case MIDI_METAEVENT_TEXT:
	      case MIDI_METAEVENT_COPYRIGHT:
	      case MIDI_METAEVENT_TRACKNAME:
	      case MIDI_METAEVENT_MAKER:
		event=new MIDIMetaTextEvent(deltaTime,type,metaData,length);
		break;
	      case MIDI_METAEVENT_SETTEMPO:
		event=new MIDIMetaNumberEvent(deltaTime,type,metaData,length);
		break;
	      default:
		event=new MIDIMetaGenericEvent(deltaTime,type,metaData,length);
		break;
	      }
	    _events.push_back(event);
	  }
	  break;
	case 0xF0: // System Exclusive Events
	case 0xF7:
	  {
	    dword length=readNextVariableLength();
	    byte sysData[length];
	    for(int i=0;i<length;i++)
	      {
		sysData[i]=readNextByte();
	      }
	    #warning "System Exclusive events are unimplemented"
	    // IGNORE
	  }
	  break;
	default:
	  { // Everything else is a channel event
	    byte command;
	    int channel;
	    byte param1;
	    byte param2;

	    if((eventType>>7)==1) // MSB of 1 indicates that the first 4 bits are the channel event type
	      {
		/*
		 * 4 bits:event type
		 * 4 bits:channel
		 * 1 byte:param1
		 * 1 byte:param2
		 */
		command=(0xF0&eventType)>>4;
		channel=(int)(0x0F & eventType);
		param1=readNextByte();
		param2=readNextByte();
	      }
	    else // This is a running status, since MSB==0
	      {
		/*
		 * Event type/channel are from previous event
		 * 1 byte:param1
		 * 1 byte:param2
		 */
		command=lastMIDICommand;
		channel=lastChannel;
		param1=eventType;
		param2=readNextByte();
	      }

	    // Store the event
	    MIDIChannelEvent *event=0;
	    if(command==MIDI_CHEVENT_CONTROLLER)
	      event=new MIDIChannelControllerEvent(deltaTime,channel,param1,param2);
	    else
	      event=new MIDIChannelEvent(deltaTime,command,channel,param1,param2);

	    _events.push_back(event);

	    lastMIDICommand=command;
	    lastChannel=channel;
	  }
	  break;
	}
    }
}

unsigned int MIDITrack::numEvents()
{
  return _events.size();
}

MIDIEvent* MIDITrack::event(unsigned int id)
{
  return _events[id];
}

void MIDITrack::addEvent(MIDIEvent* event)
{
  _events.push_back(event);
}

dword MIDITrack::readNextVariableLength()
{
  dword result=0;
  bool flag=0;
  do
    {
      byte i=_data[_pos];
      dword contribution=(dword)(0x7F & i); // Ignore first bit, it is a flag
      // Shift down to make space for new bit
      result=(result<<7);
      result+=contribution;

      flag=(0x80 & i); // The first bit is 0 if this is the final contribution

      _pos++;
    } while(flag);

  return result;
}

byte MIDITrack::readNextByte()
{
  byte result=_data[_pos];
  _pos++;
  return result;
}

MIDIDataBuffer MIDITrack::data()
{
  MIDIDataBuffer data(1000000);

  byte lastCommand=MIDI_CHEVENT_INVALID;

  for(int i=0;i<_events.size();i++)
    {
      MIDIDataBuffer eventData;
      if(_events[i]->type()==MIDI_CHEVENT)
	{
	  MIDIChannelEvent *chevent=(MIDIChannelEvent*)_events[i];
	  if(chevent->command()==lastCommand)
	    eventData=chevent->data(true);
	  else
	    eventData=chevent->data(false);

	  lastCommand=chevent->command();
	}
      else
	eventData=_events[i]->data();
	
      data.write(eventData);
    }

  return data;
}
