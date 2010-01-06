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

#ifndef MIDIFILE_H_
#define MIDIFILE_H_

#include <vector>
#include <string>
using namespace std;

#include "Chunk.h"

#include "Header.h"
#include "Track.h"

namespace MIDI
{
  //! Class that describes a MIDI file
  /*!
   * This is the main class of libmidi, and is designed such that it reflects the
   * physical structore of a midi file.
   *
   * The class is given a path to a MIDI file in the constructor. Calling MIDI::File::open() 
   * then parses the file and stores the information.
   *
   * A MIDI file is divided into chunks. The first chunk is the header. The rest is tracks.
   */
  class File
  {
  public:
    //! Constructor
    /*!
     * Call MIDI::File::open() to parse the MIDI file
     *
     * \param path Path to the MIDI file that is represented by this object
     */
    File(string path);
    
    //! Change the MIDI file
    /*!
     * This function does nothing other than change the path.
     * Use MIDI::File::open() or MIDI::File::write() to do something.
     *
     * \param path Path to new MIDI file
     */
    void setPath(string path);
    
    //! Parse the MIDI file
    /*!
     * Opens and extracs header and tracks from the midi file specified in the constructor
     *
     * \return False if there were problems, true otherwise.
     */
    bool open();
    
    //! Save to MIDI file
    /*!
     * Writes out the header and tracks to the midi file specified in the path variable
     *
     * \return False if there were problems, true otherwise
     */
    bool write();
    
    /*!
     * \return The header chunk
     */
    Header* header();
    
    /*!
     * \return The idth track chunk
     */
    Track* track(unsigned int id);
    
    /*!
     * Append a new track to the end of the track list
     * \param track Track to append
     */
    void addTrack(Track* track);
    
    /*!
     * \return Number of tracks found in this MIDI file
     */
    unsigned int numTracks();
    
  protected:
    /*!
     * Tries to read the next chunk from the input file stream.
     * \return The chunk that was read.
     */
    Chunk* readChunk(ifstream& fh);
    
  private:
    string _path;
    
    Header *_header;
    vector<Track*> _tracks;
  };
}

#endif // MIDIFILE_H_
