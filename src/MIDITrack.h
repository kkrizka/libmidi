#ifndef MIDITRACK_H_
#define MIDITRACK_H_

#include "MIDIChunk.h"
#include "MIDIChannelEvent.h"
#include "MIDIMetaEvent.h"

#include <vector>
using namespace std;

//! Tracks are sequences of events.
/*!
 * There are three types of events
 * <ul>
 *  <li>Meta events: Not sent to the synchronizer</li>
 *  <li>Channel events: Sent to a synchronizer</li>
 *  <li>System Exclusive events: Events exclusive to specific hardware, ignored by libmidireader</li>
 * </ul>
 */
class MIDITrack : public MIDIChunk
{
public:
  //! Default Constructor
  /*!
   * Creates an empty track with 0 events
   */
  MIDITrack();

  //! Constructor
  /*!
   * Parses data for events and stores them.
   *
   * \param data The data
   * \param size Number of bytes of data
   */
  MIDITrack(byte* data,dword size);

  /*!
   * \return Number of events in this track.
   */
  unsigned int numEvents();

  /*!
   * Events are stored in the same order as they are found in the MIDI file.
   *
   * \return Event number id
   */
  MIDIEvent* event(unsigned int id);

  /*!
   * Add a new event to the end of the track
   *
   * \param event New event
   */
  void addEvent(MIDIEvent* event);


  /*!
   * \return This track represented as data in a MIDI file
   */
  MIDIDataBuffer data();

private:
  dword readNextVariableLength();
  byte readNextByte();

  byte* _data;
  dword _size;
  dword _pos;

  vector<MIDIEvent*> _events;
};

#endif // MIDITRACK_H_
