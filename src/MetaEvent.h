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

#ifndef MIDIMETAEVENT_H_
#define MIDIMETAEVENT_H_

#include "types.h"

#include "Event.h"

namespace MIDI
{
  /*!
   * Meta events are events that are not send to a synchronizer. This
   * class represents an abstract meta event.
   *
   * There are several types of events, each of which is referenced
   * by some meta type. See the MIDI specification for different 
   * meta types.
   */
  class MetaEvent : public Event
  {
  public:
    //! Default constructor
    MetaEvent();
    //! Copy constructor
    MetaEvent(const MetaEvent& o);
    //! Constructor
    MetaEvent(dword deltaTime,byte metatype);
    
    /*!
     * \return MIDI_METAEVENT, since this is a channel event
     */
    EventType type();
    
    /*!
     * \return The type of the meta event. See MIDI specification
     */
    byte metaType();
    
    /*!
     * \return This meta event represented as data in a MIDI file
     */
    virtual DataBuffer data();

    //! Print debug information
    virtual void debug();
    
  private:
    byte _metaType;
  };
}

#endif // MIDIMETAEVENT_H_
