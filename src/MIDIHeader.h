#ifndef MIDIHEADER_H_
#define MIDIHEADER_H_

#include "MIDIChunk.h"

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
class MIDIHeader : public MIDIChunk
{
public:
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
  MIDIHeader(byte* data,dword size);

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
  int numTracks();

  /*!
   * Used for translating the time deltas in events into real times. It can be stored
   * as either ticks per beat or frames per second. 
   *
   * This function retuns the value that is stored inside the header. For decoded values,
   * see other access functions.
   *
   * \see MIDIHeader::ticksPerBeat()
   * \see MIDIHeader::framesPerSecond()
   * \return Time divisions as stored in the header
   */
  int timeDivisions();
 
  /*!
   * Number of time delta positions per quarter note of music
   *
   * \return ticks per beat, 0 if defined as frames per second
   */
  unsigned int ticksPerBeat();

  /*!
   * \see MIDIHeader::ticksPerFrame()
   * \return Frames per second, 0 if defined as ticks per beat
   */
  unsigned int framesPerSecond();

  /*!
   * Ticks per frame, when timing is defined as frames per second.
   * \see MIDIHeader::framesPerSecond()
   * \return Ticks per frame, 0 if defined as ticks per beat
   */
  unsigned int ticksPerFrame();

private:
  int _formatType;
  int _nTracks;
  int _timeDivisions;
};

#endif // MIDIHEADER_H_
