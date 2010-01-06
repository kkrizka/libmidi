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

#ifndef MIDIHEADER_H_
#define MIDIHEADER_H_

#include "Chunk.h"

namespace MIDI
{
  //! Class that contains the header chunk of a MIDI file
  /*!
   * The header chunk contains the following information:
   * <ul>
   *  <li>Format type</li>
   *  <li>Number of tracks</li>
   *  <li>Time Divisions</li>
   * </ul>
   * 
   * Each is described below. For more details, see the MIDI specification.
   */
  class Header : public Chunk
  {
    public:
      //! Default constructor
      /*!
       * Creates an empty MIDI header with all properties set to 0
       */
      Header();

      //! Constructor
      /*!
       * Parses the array data to determine the contents of the header. The data is the 
       * set of bits after the chunk id and the chunk size.
       * 
       * Note: This constructor is not meant to be used outside of MIDIFile
       *
       * \param data The data
       * \param size The number of bytes of data
       */
      Header(byte* data,dword size);

      /*!
       * The following format types exist:
       * <ul>
       *  <li>0: single track file format</li>
       *  <li>1: multiple track file forma</li>
       *  <li>2: multiple song file format (series of type 0 files)</li>
       * </ul>
       *
       * \return Format type of the MIDI
       */
      int formatType();
      
      /*!
       * \return Number of tracks in the MIDI file
       */
      unsigned int numTracks();
      
      /*!
       * Set the number of tracks in the MIDI file.
       *
       * Be careful when using this function. File::write() does not check that 
       * this value corresponds to the actual number of tracks.
       *
       * \param numTracks New value
       */
      void setNumTracks(unsigned int numTracks);
      
      
      /*!
       * Used for translating the time deltas in events into real times. It can be stored
       * as either ticks per beat or frames per second. 
       *
       * This function retuns the value that is stored inside the header. For decoded values,
       * see other access functions.
       *
       * \see Header::ticksPerBeat()
       * \see Header::framesPerSecond()
       * \return Time divisions as stored in the header
       */
      int timeDivisions();
 
      /*!
       * Number of time delta positions per quarter note of music
       *
       * \return ticks per beat, 0 if defined as frames per second
       */
      unsigned int ticksPerBeat();

      //! Number of time delta positions per quarter note of music.
      /*!
       * Using this functions nullifies any previous calls to Header::setFramesPerSecond()
       * and Header::setTicksPerFrame()
       *
       * \param ticksPerBeat ticks per beat
       */
      void setTicksPerBeat(unsigned int ticksPerBeat);
      
      /*!
       * \see MIDIHeader::ticksPerFrame()
       * \return Frames per second, 0 if defined as ticks per beat
       */
      unsigned int framesPerSecond();
      
      //! Set frames per second
      /*!
       * Using this functions nullifies any previous calls to Header::setTicksPerBeat()
       * \param framesPerSecond
       */
      void setFramesPerSecond(unsigned int setFramesPerSecond);
      
      /*!
       * Ticks per frame, when timing is defined as frames per second.
       * \see MIDIHeader::framesPerSecond()
       * \return Ticks per frame, 0 if defined as ticks per beat
       */
      unsigned int ticksPerFrame();
      
      /*!
       * Using this functions nullifies any previous calls to Header::setTicksPerBeat()
       * \see MIDIHeader::setFramesPerSecond()
       * \param ticksPerFrame 
       */
      void setTicksPerFrame(unsigned int ticksPerFrame);
      
      /*!
       * \return This header represented as data in a MIDI file
       */
      DataBuffer data();
      
      
    private:
      int _formatType;
      unsigned int _numTracks;
      int _timeDivisions;
    };
}
#endif // MIDIHEADER_H_
