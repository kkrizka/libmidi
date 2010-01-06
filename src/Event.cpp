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

#include "Event.h"

#include <iostream>
using namespace std;

namespace MIDI
{
  Event::Event()
    : _deltaTime(0)
  { }
  
  Event::Event(const Event& o)
    : _deltaTime(o._deltaTime)
  { }
  
  Event::Event(dword deltaTime)
    : _deltaTime(deltaTime)
  { }
  
  dword Event::deltaTime()
  {
    return _deltaTime;
  }
  
  DataBuffer Event::data()
  {
    DataBuffer data(10000);
    data.writeVariableLength(_deltaTime);
    return data;
  }
  
  void Event::debug()
  {
    cout << "\tMIDI Event" << endl;
  }
}
