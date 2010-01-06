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

#ifndef MIDIMETANUMBEREVENT_H_
#define MIDIMETANUMBEREVENT_H_

#include "MetaEvent.h"

namespace MIDI
{
  /*!
   * Number events are special events that contains only one large (larger than a byte)
   * number data field.
   *
   * These events are always stored in fixed-length strings
   *
   * These currently include:
   * <ul>
   *  <li>MIDI_METAEVENT_SETTEMPO</li>
   * </ul>
   */
  class MetaNumberEvent : public MetaEvent
  {
  public:
    //! Default Constructor
    MetaNumberEvent();
    //! Copy Constructor
    MetaNumberEvent(const MetaNumberEvent& o);
    //! Constructor
    MetaNumberEvent(dword deltaTime,byte metaType,dword length,unsigned int value=0);
    //! Constructor
    MetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length);
    
    /*!
     * \return The number stored in this event
     */
    unsigned int number();
    
    /*!
     * The number is stored in the same length string as it came in.
     *
     * \return This meta number event represented as data in a MIDI file
     */
    virtual DataBuffer data();
    
    //! Print debug information
    virtual void debug();
    
  private:
    unsigned int _number;
    
    dword _length;
  };
}

#endif //MIDIMETANUMBEREVENT_H_
