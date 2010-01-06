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

#ifndef MIDICHUNK_H_
#define MIDICHUNK_H_

#include "types.h"

#include "DataBuffer.h"

namespace MIDI
{
  /*!
   * MIDI files are made out of chunks. This represents one chunk.
   * A chunk contains the following information:
   * <ul>
   * <li>ID (MThd,MTrk)</li>
   * <li>Size</li>
   * <li>Data</li>
   * </ul>
   *
   * None of that information is stored explecitely, although it is
   * stored implicitely in sub-classes.
   * \see MIDI::Header
   * \see MIDI::Track
   */
  class Chunk
  {
  public:
    //! Constructor
    Chunk();
    
    /*!
     * \return data to be written out
     */
    virtual DataBuffer data();
  };
}

#endif // MIDICHUNK_H_
