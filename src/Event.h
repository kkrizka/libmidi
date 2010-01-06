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

#ifndef MIDIEVENT_H_
#define MIDIEVENT_H_

#include "types.h"

#include "Defines.h"
#include "DataBuffer.h"

namespace MIDI
{
  //! An event inside a track
  /*!
   * A MIDI track is made out of events. This class is an abstract event.
   *
   * There are three types of events
   * <ul>
   *  <li>Meta events: Not sent to the synchronizer</li>
   *  <li>Channel events: Sent to a synchronizer</li>
   *  <li>System Exclusive events: Events exclusive to specific hardware, ignored by libmidireader</li>
   * </ul>
   *
   * Each event contains a "delta time" field. This is the number of ticks to wait
   * after the previous event before this event is executed. A delta time of 0 means 
   * that this event is to be executed as the same time as the previous event.
   * See MIDIHeader for how long each tick is.
   *
   * \see MIDI::MetaEvent
   * \see MIDI::ChannelEvent
   */
  class Event
  {
  public:
    /*!
     * \return Number of ticks to wait after previous event to execute this one.
     */
    dword deltaTime();
    
    /*!
     * \return The type (meta,channel,system) that this event is
     */
    virtual EventType type() =0;
    
    /*!
     * \return This event represented as data in a MIDI file
     */
    virtual DataBuffer data();
    
    //! Prints out information about this event. Is for debug purposes.
    virtual void debug();

  protected:
    //! Empty constructor
    Event();
    //! Copy constructor
    Event(const Event& o);
    //! Contructor
    Event(dword deltaTime);

  private:
    dword _deltaTime;
  };
}

#endif // MIDIEVENT_H_
