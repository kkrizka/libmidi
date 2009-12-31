#ifndef MIDIFILE_H_
#define MIDIFILE_H_

#include <vector>
#include <string>
using namespace std;

#include "MIDIChunk.h"

#include "MIDIHeader.h"
#include "MIDITrack.h"

//! Class that describes a MIDI file
/*!
 * This is the main class of libmidireader, and is designed such that it reflects the
 * physical structore of a midi file.
 *
 * The class is given a path to a MIDI file in the constructor. Calling MIDIFile::open() 
 * then parses the file and stores the information.
 *
 * A MIDI file is divided into chunks. The first chunk is the header. The rest is tracks.
 */
class MIDIFile
{
public:
  //! Constructor
  /*!
   * Call MIDIFile::open() to parse the MIDI file
   *
   * \param path Path to the MIDI file that is represented by this object
   */
  MIDIFile(string path);

  //! Change the MIDI file
  /*!
   * This function does nothing other than change the path.
   * Use MIDIFile::open() or MIDIFile::write() to do something.
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
   * Writes out the header and tracks to the midi file specified in the constructor
   *
   * \return False if there were problems, true otherwise
   */
  bool write();

  /*!
   * \return The header chunk
   */
  MIDIHeader* header();

  /*!
   * \return The idth track chunk
   */
  MIDITrack* track(unsigned int id);

  /*!
   * Append a new track to the end of the track list
   * \param track Track to append
   */
  void addTrack(MIDITrack* track);

  /*!
   * \return Number of tracks found in this MIDI file
   */
  unsigned int numTracks();

protected:
  /*!
   * Tries to read the next chunk from the input file stream.
   * \return The chunk that was read.
   */
  MIDIChunk* readChunk(ifstream& fh);

private:
  string _path;

  MIDIHeader *_header;
  vector<MIDITrack*> _tracks;
};

#endif // MIDIFILE_H_
