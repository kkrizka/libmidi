#ifndef MIDICHUNK_H_
#define MIDICHUNK_H_

#include "types.h"

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
 * \see MIDIHeader
 * \see MIDITrack
 */
class MIDIChunk
{
public:
  //! Constructor
  /*!
   * \param data The data
   * \param size Number of bytes of data
   */
  MIDIChunk(byte* data, dword size);
};

#endif // MIDICHUNK_H_
