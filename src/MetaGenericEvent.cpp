/*
  Copyright (C) 2010 Karol Krizka <kkrizka@gmail.com>
  
  URL: http://www.krizka.net/projects/libmidi/
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  $Id$
*/

#include "MetaGenericEvent.h"

#include "Defines.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace MIDI
{
  MetaGenericEvent::MetaGenericEvent()
    : MetaEvent(),_data(0),_dataLength(0)
  { }
  
  MetaGenericEvent::MetaGenericEvent(const MetaGenericEvent& o)
    : MetaEvent(o),_data(0),_dataLength(o._dataLength)
  {
    _data=new byte[_dataLength];
    for(int i=0;i<_dataLength;i++)
      {
	_data[i]=o._data[i];
      }
  }
  
  MetaGenericEvent::MetaGenericEvent(dword deltaTime,byte metaType,byte data[],int dataLength)
    : MetaEvent(deltaTime,metaType),_data(0),_dataLength(dataLength)
  {
    _data=new byte[_dataLength];
    for(int i=0;i<_dataLength;i++)
      {
	_data[i]=data[i];
      }
  }
  
  MetaGenericEvent::MetaGenericEvent(dword deltaTime,byte metaType,int dataLength)
    : MetaEvent(deltaTime,metaType),_data(0),_dataLength(dataLength)
  {
    _data=new byte[_dataLength];
    for(int i=0;i<_dataLength;i++)
      {
	_data[i]='\0';
      }
  }
  
  int MetaGenericEvent::dataLength()
  {
    return _dataLength;
  }
  
  int MetaGenericEvent::paramInt(unsigned int id)
  {
    return (int)_data[id];
  }
  
  unsigned int MetaGenericEvent::paramUInt(unsigned int id)
  {  
    return char2num((char)_data[id]);
  }
  
  void MetaGenericEvent::setParam(unsigned int id,byte value)
  {
    _data[id]=value;
  }
  
  DataBuffer MetaGenericEvent::data()
  {
    DataBuffer data=MetaEvent::data();
    
    data.writeVariableLength(_dataLength);
    for(int i=0;i<_dataLength;i++)
      {
	data.write(_data[i]);
      }
    
    return data;
  }
  
  void MetaGenericEvent::debug()
  {
    switch(metaType())
      {
      case MIDI_METAEVENT_PORT:
	cout << "\tMIDI Port" << endl;
	cout << "\t\tPort: " << paramUInt(0) << endl;
	break;
      case MIDI_METAEVENT_TIMESIGNATURE:
	cout << "\tTime Signature" << endl;
	cout << "\t\tNumerator: " << paramUInt(0) << endl;
	cout << "\t\tDenominator: " << paramUInt(1) << endl;
	cout << "\t\tMetronome: " << paramUInt(2) << endl;
	cout << "\t\t32nds: " << paramUInt(3) << endl;
	break;
      case MIDI_METAEVENT_KEYSIGNATURE:
	cout << "\tKey Signature" << endl;
	cout << "\t\tKey: " << paramInt(0) << endl;
	cout << "\t\tScale: " << paramUInt(1) << endl;
	break;
      case MIDI_METAEVENT_ENDOFTRACK:
	cout << "\tEnd of Track" << endl;
	break;
      default:
	cout << "\tGeneric Meta Event 0x" << setbase(16) << (unsigned int)metaType() << endl;
	for(int i=0;i<_dataLength;i++)
	  {
	    cout << "\t\t0x" << setbase(16) << paramInt(i) << endl;
	  }
	break;
      }
  }
}
