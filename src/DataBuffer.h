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

#ifndef MIDIDATABUFFER_H_
#define MIDIDATABUFFER_H_

#include "types.h"

namespace MIDI
{
  /*!
   * Class that represents a read/write buffer of bytes. Can be navigated
   * using interfaces like a C++ STD stream.
   *
   * Also contains functions that help to read data as if it were stored
   * in a MIDI file. These include support for variable-length fields.
   *
   * As of right now, buffers can be expanded only to a specified maximum length.
   *
   * A buffer owns its data.
   */
  class DataBuffer
  {
  public:
    //! Constructor
    /*!
     * Creates an empty buffer, with 0 maximum length
     */
    DataBuffer();
    //! Copy constructor
    DataBuffer(const DataBuffer& o);
    /*!
     * Initializes the data by copying the first "size" number of bytes from the
     * data array. The data is copied explicitely.
     *
     * This buffer can store at most size bytes.
     *
     * \param data The data to copy
     * \param size Number of bytes to copy from the data array
     */
    DataBuffer(byte data[],unsigned int size);
    /*!
     * Initialize an empty data buffer that can store at most maxsize bytes.
     *
     * \param maxsize Maximum number of bytes that one can store in this buffer
     */
    DataBuffer(unsigned int maxsize);
    
    /*!
      \return Array access to the underlying data
    */
    byte* data();

    /*!
     * \return Number of bytes stored in this buffer
     */
    unsigned int size();

    /*!
     * \return The maximum possible number of bytes that can be  stored in this buffer
     */
    unsigned int maxsize();
    
    /*!
     * Write a number of variable length into the buffer, at current pos.
     *
     * \param data The number to write. Can be at most 4 bytes.
     */
    void writeVariableLength(dword data);

    /*!
     * Write a byte into the buffer, and increment the position counter/
     *
     * \param data byte to write
     */
    void write(byte data);

    /*!
     * Write a whole set of bytes into the buffer. Increments position counter
     * by size.
     * 
     * \param data Array of data to write
     * \param size Number of bytes from data[] to write
     */
    void write(byte data[],unsigned int size);

    /*!
     * Write all data from another MIDI::DataBuffer to this buffer.
     *
     * \param data MIDI::DataBuffer to copy from
     */
    void write(DataBuffer data);
    
    /*!
     * Moves the position counter somewhere else. The beginning of the buffer
     * is pos=0
     *
     * \param pos Position to seek to
     */
    void seek(int pos);
    
    /*!
     * Removes number of bytes at the current positions. All bytes after the removed
     * ones are shifted down.
     *
     * \param numBytes Number of bytes to remove
     */
    void remove(int numBytes);
    
  private:
    byte* _data;
    unsigned int _size;
    unsigned int _maxsize;
    
    unsigned int _pos;
  };
}

#endif // MIDIDATABUFFER_H_
