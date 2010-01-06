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

#ifndef MIDIMETAGENERICEVENT_H_
#define MIDIMETAGENERICEVENT_H_

#include "types.h"

#include "MetaEvent.h"

namespace MIDI
{
  /*!
   * This class represents a generic meta event.
   *
   * A generic meta event contains byte long data that can be accessed by some index.
   *
   * This represents all events not represented by specific classes.
   */
  class MetaGenericEvent : public MetaEvent
  {
  public:
    //! Default constructor
    MetaGenericEvent();
    //! Copy constructor
    MetaGenericEvent(const MetaGenericEvent& o);
    //! Constructor
    /*!
     * \param deltaTime
     * \param metaType
     * \param data Data that will be initialized
     * \param data Length Number of data pieces
     */
    MetaGenericEvent(dword deltaTime,byte metaType,byte data[],int dataLength);
    //! Constructor
    /*!
     * Initializes with null data
     *
     * \param deltaTime
     * \param metaType
     * \param data Length Number of data pieces that will exist
     */
    MetaGenericEvent(dword deltaTime,byte metaType,int dataLength);
    
    /*!
     * \return Number of data fields stored in this event
     */
    int dataLength();
    
    /*!
     * Allows access to data as if it were stored as a signed integer.
     *
     * \param id The id of the data
     * \return The value of the data
     */
    int paramInt(unsigned int id);
    
    /*!
     * Allows access to data as if it were stores as an unsigned integer.
     *
     * \param id The id of the data
     * \return The value of the data
     */   
    unsigned int paramUInt(unsigned int id);
    
    /*!
     * Set parameter to byte
     *
     * \param id The id of the data
     * \param value What to save
     */
    void setParam(unsigned int id,byte value);
    
    /*!
     * \return This meta event represented as data in a MIDI file
     */
    virtual DataBuffer data();
    
    //! Prints debug information
    virtual void debug();
    
  private:
    byte* _data;
    int _dataLength;
  };
}
#endif // MIDIMETAGENERICEVENT_H_
