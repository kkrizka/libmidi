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

#ifndef MIDIMETATEXTEVENT_H_
#define MIDIMETATEXTEVENT_H_

#include "MetaEvent.h"

#include <string>
using namespace std;

namespace MIDI
{
  /*!
   * Text events are special events that contains only one text data field
   *
   * These currently include:
   * <ul>
   *  <li>MIDI_METAEVENT_TEXT</li>
   *  <li>MIDI_METAEVENT_COPYRIGHT</li>
   *  <li>MIDI_METAEVENT_TRACKNAME</li>
   *  <li>MIDI_METAEVENT_MAKER</li>
   * </ul>
   */
  class MetaTextEvent : public MetaEvent
  {
  public:
    //! Default Constructor
    MetaTextEvent();
    //! Copy Constructor
    MetaTextEvent(const MetaTextEvent& o);
    //! Constructor
    MetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length);
    
    /*!
     * \return The text of this event
     */
    string text();
    
    /*!
     * \return This meta text event represented as data in a MIDI file
     */
    virtual DataBuffer data();
    
    //! Print debug information
    virtual void debug();
    
  private:
    string _text;
  };
}

#endif //MIDIMETATEXTEVENT_H_
