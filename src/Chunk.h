#ifndef MIDICHUNK_H_
#define MIDICHUNK_H_

#include "types.h"

#include "DataBuffer.h"

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
namespace MIDI
{
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
