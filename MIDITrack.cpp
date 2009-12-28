#include "MIDITrack.h"

#include <iostream>
#include <iomanip>
using namespace std;

MIDITrack::MIDITrack(char* data,dword size)
  : MIDIChunk(data,size),_data(data),_size(size),_pos(0)
{
  int lastMIDIType;
  int lastChannel;

  while(_pos<_size)
    {
      int deltaTime=readNextVariableLength();
      int eventType=readNext();
      
      switch(eventType)
	{
	case 0xFF: //Meta event
	  {
	    int type=readNext();
	    int length=readNextVariableLength();
	    int data[length];
	    for(int i=0;i<length;i++)
	      {
		data[i]=readNext();
	      }
	    handleMetaEvent(type,data,length);
	  }
	  break;
	case 0xF0: // System Exclusive Events
	case 0xF7:
	  {
	    int length=readNextVariableLength();
	    int data[length];
	    for(int i=0;i<length;i++)
	      {
		data[i]=readNext();
	      }
	    cout << "\tSystem Exclusive Event" << endl;
	    // IGNOREx
	  }
	  break;
	default:
	  { // Everything else is a channel event
	    int type;
	    int channel;
	    int param1;
	    int param2;
	    if((eventType>>7)==1) // MSB of 1 indicates that the first 4 bits are the channel event type
	      {
		/*
		 * 4 bits:event type
		 * 4 bits:channel
		 * 1 byte:param1
		 * 1 byte:param2
		 */
		type=(0xF0&eventType)>>4;
		channel=0x0F&eventType;
		param1=readNext();
		param2=readNext();
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
		param2=readNext();
	      }

	    // Store the event
	    MIDIChannelEvent event(deltaTime,type,channel,param1,param2);
	    event.debug(); //print
	    _channelEvents.push_back(event);

	    lastMIDIType=type;
	    lastChannel=channel;
	  }
	  break;
	}
    }
  cout << setbase(10);
}

int MIDITrack::readNextVariableLength()
{
  int result=0;
  int flag=0;
  do
    {
      int i=(int)_data[_pos];
      int contribution=0x7F & i; // Ignore first bit, it is a flag
      result=(result<<7);
      result+=contribution;

      flag=0x80 & i; // The first bit is 0 if this is the final contribution

      _pos++;
    } while(flag!=0);

  return result;
}

int MIDITrack::readNext()
{
  int result=char2num(_data[_pos]);
  _pos++;
  return result;
}

char* MIDITrack::data2cstr(int data[],int length)
{
  char *result=new char[length+1];
  for(int i=0;i<length;i++)
    {
      result[i]=num2char(data[i]);
    }
  result[length]='\0';
  return result;
}

void MIDITrack::handleMetaEvent(int type,int data[],int length)
{
  switch(type)
    {
    case 0x1:
      {
	char* str=data2cstr(data,length);
	cout << "\tText" << endl;
	cout << "\t\t" << str;
      }
      break;
    case 0x2:
      {
	char* str=data2cstr(data,length);
	cout << "\tCopyright" << endl;
	cout << "\t\t" << str << endl;
      }
      break;
    case 0x3:
      {
	char* str=data2cstr(data,length);
	cout << "\tTrack Name: " << str << endl;
      }
      break;
    case 0x6:
      {
	char* str=data2cstr(data,length);
	cout << "\tMaker: " << str << endl;
      }
      break;
    case 0x51:
      {
	int tempo=0;
	for(int i=0;i<3;i++)
	  {
	    tempo=(tempo<<8);
	    tempo+=data[i];
	  }
	cout << "\tSet Tempo" << endl;
	cout << "\t\tMicroseconds/Quarter-note: " << tempo << endl;
      }
      break;
    case 0x21:
      cout << "\tMIDI Port" << endl;
      cout << "\t\tPort: " << data[0] << endl;
      break;
    case 0x58:
      cout << "\tTime Signature" << endl;
      cout << "\t\tNumerator: " << data[0] << endl;
      cout << "\t\tDenominator: " << data[1] << endl;
      cout << "\t\tMetronome: " << data[2] << endl;
      cout << "\t\t32nds: " << data[3] << endl;
      break;
    case 0x59:
      cout << "\tKey Signature" << endl;
      cout << "\t\tKey: " << (int)num2char(data[0]) << endl;
      cout << "\t\tScale: " << data[1] << endl;
      break;
    case 0x2F:
      cout << "\tEnd of Track" << endl;
      break;
    default:
      cout << "\t" << "Meta Event Type 0x" << setbase(16) << type << setbase(10) << endl;
      break;
    }
}

void MIDITrack::handleControllerEvent(int type,int value)
{
  switch(type)
    {
    case 0x7:
      cout << "\tMain Volume" << endl;
      break;
    case 0xa:
      cout << "\tPan" << endl;
      break;
    case 0x5D:
      cout << "\tEffect 3 Depth (Chorus Depth)" << endl;
      break;
    default:
      cout << "\tController Event 0x" << setbase(16) << type << endl;
      break;
    }
  cout << "\t\tValue: " << setbase(10) << value << endl;
}
