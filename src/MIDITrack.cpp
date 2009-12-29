#include "MIDITrack.h"

#include "MIDIChannelControllerEvent.h"
#include "MIDIMetaGenericEvent.h"
#include "MIDIMetaTextEvent.h"
#include "MIDIMetaNumberEvent.h"
#include "MIDIDefines.h"

MIDITrack::MIDITrack(byte* data,dword size)
  : MIDIChunk(data,size),_data(data),_size(size),_pos(0)
{
  byte lastMIDIType;
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
	    byte data[length];
	    for(int i=0;i<length;i++)
	      {
		data[i]=readNextByte();
	      }

	    MIDIMetaEvent *event;
	    switch(type)
	      {
	      case MIDI_METAEVENT_TEXT:
	      case MIDI_METAEVENT_COPYRIGHT:
	      case MIDI_METAEVENT_TRACKNAME:
	      case MIDI_METAEVENT_MAKER:
		event=new MIDIMetaTextEvent(deltaTime,type,data,length);
		break;
	      case MIDI_METAEVENT_SETTEMPO:
		event=new MIDIMetaNumberEvent(deltaTime,type,data,length);
		break;
	      default:
		event=new MIDIMetaGenericEvent(deltaTime,type,data,length);
		break;
	      }
	    _events.push_back(event);

	    //handleMetaEvent(type,data,length);
	  }
	  break;
	case 0xF0: // System Exclusive Events
	case 0xF7:
	  {
	    dword length=readNextVariableLength();
	    byte data[length];
	    for(int i=0;i<length;i++)
	      {
		data[i]=readNextByte();
	      }
	    #warning "System Exclusive events are unimplemented"
	    // IGNORE
	  }
	  break;
	default:
	  { // Everything else is a channel event
	    byte type;
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
		type=(0xF0&eventType)>>4;
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
		type=lastMIDIType;
		channel=lastChannel;
		param1=eventType;
		param2=readNextByte();
	      }

	    // Store the event
	    MIDIChannelEvent *event=0;
	    if(type==MIDI_CHEVENT_CONTROLLER)
	      event=new MIDIChannelControllerEvent(deltaTime,channel,param1,param2);
	    else
	      event=new MIDIChannelEvent(deltaTime,type,channel,param1,param2);

	    _events.push_back(event);

	    lastMIDIType=type;
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
