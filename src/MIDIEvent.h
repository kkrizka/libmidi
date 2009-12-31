#ifndef MIDIEVENT_H_
#define MIDIEVENT_H_

#include "types.h"

#include "MIDIDefines.h"
#include "MIDIDataBuffer.h"

//! An event inside a track
/*!
 * A MIDI track is made out of events. This class is an abstract event.
 *
 * There are three types of events
 * <ul>
 *  <li>Meta events: Not sent to the synchronizer</li>
 *  <li>Channel events: Sent to a synchronizer</li>
 *  <li>System Exclusive events: Events exclusive to specific hardware, ignored by libmidireader</li>
 * </ul>
 *
 * Each event contains a "delta time" field. This is the number of ticks to wait
 * after the previous event before this event is executed. A delta time of 0 means 
 * that this event is to be executed as the same time as the previous event.
 * See MIDIHeader for how long each tick is.
 *
 * \see MIDIMetaEvent
 * \see MIDIChannelEvent
 */
class MIDIEvent
{
public:
  /*!
   * \return Number of ticks to wait after previous event to execute this one.
   */
  dword deltaTime();

  /*!
   * \return The type (meta,channel,system) that this event is
   */
  virtual MIDIEventType type() =0;

  /*!
   * \return This event represented as data in a MIDI file
   */
  virtual MIDIDataBuffer data();
  
  //! Prints out information about this event. Is for debug purposes.
  virtual void debug();

protected:
  //! Empty constructor
  MIDIEvent();
  //! Copy constructor
  MIDIEvent(const MIDIEvent& o);
  //! Contructor
  MIDIEvent(dword deltaTime);

private:
  dword _deltaTime;
};

#endif // MIDIEVENT_H_
