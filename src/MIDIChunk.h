#ifndef MIDICHUNK_H_
#define MIDICHUNK_H_

#include "types.h"

#include "MIDIDataBuffer.h"

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
  MIDIChunk();

  /*!
   * \return data to be written out
   */
  virtual MIDIDataBuffer data();
};

#endif // MIDICHUNK_H_
