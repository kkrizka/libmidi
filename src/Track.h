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

#ifndef MIDITRACK_H_
#define MIDITRACK_H_

#include "Chunk.h"
#include "ChannelEvent.h"
#include "MetaEvent.h"

#include <vector>
using namespace std;

namespace MIDI
{
  //! Tracks are sequences of events.
  /*!
   * There are three types of events
   * <ul>
   *  <li>Meta events: Not sent to the synchronizer</li>
   *  <li>Channel events: Sent to a synchronizer</li>
   *  <li>System Exclusive events: Events exclusive to specific hardware, ignored by libmidireader</li>
   * </ul>
   */
  class Track : public Chunk
    {
    public:
      //! Default Constructor
      /*!
       * Creates an empty track with 0 events
       */
      Track();
      
      //! Constructor
      /*!
       * Parses data for events and stores them.
       *
       * \param data The data
       * \param size Number of bytes of data
       */
      Track(byte* data,dword size);

      /*!
       * \return Number of events in this track.
       */
      unsigned int numEvents();
      
      /*!
       * Events are stored in the same order as they are found in the MIDI file.
       *
       * \return Event number id
       */
      Event* event(unsigned int id);
      
      /*!
       * Add a new event to the end of the track. The new event is 
       * pushed at the end of the list.
       *
       * \param event New event
       */
      void addEvent(Event* event);
      

      /*!
       * \return This track represented as data in a MIDI file
       */
      DataBuffer data();
      
    private:
      dword readNextVariableLength();
      byte readNextByte();
      
      byte* _data;
      dword _size;
      dword _pos;
      
      vector<Event*> _events;
    };
}
#endif // MIDITRACK_H_
