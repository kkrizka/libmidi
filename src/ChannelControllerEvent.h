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

#ifndef MIDICHANNELCONTROLLEREVENT_H_
#define MIDICHANNELCONTROLLEREVENT_H_

#include "ChannelEvent.h"

namespace MIDI
{
  /*!
   * Controller events are special events that have a sub type and a value.
   *
   * See the MIDI specification for a complete list of contoller event types.
   */
  class ChannelControllerEvent : public ChannelEvent
  {
  public:
    //! Default Constructor
    ChannelControllerEvent();
    //! Copy Constructor
    ChannelControllerEvent(const ChannelControllerEvent& o);
    //! Constructor
    ChannelControllerEvent(dword deltaTime,int channel,int controllertype,int value);
    
    /*!
     * \return The sub type of this controller event
     */
    int controllerType();
    
    /*!
     * \return Value held by this sub type
     */
    int value();
    
    //! Print debug information
    virtual void debug();
    
  private:
    int _controllertype;
    int _value;
  };
}

#endif // MIDICHANNELCONTROLLEREVENT_H_
