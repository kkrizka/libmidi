#ifndef MIDIMETAEVENT_H_
#define MIDIMETAEVENT_H_

#include "types.h"

#include "MIDIEvent.h"

/*!
 * Meta events are events that are not send to a synchronizer. This
 * class represents an abstract meta event.
 *
 * There are several types of events, each of which is referenced
 * by some meta type. See the MIDI specification for different 
 * meta types.
 */
class MIDIMetaEvent : public MIDIEvent
{
public:
  //! Default constructor
  MIDIMetaEvent();
  //! Copy constructor
  MIDIMetaEvent(const MIDIMetaEvent& o);
  //! Constructor
  MIDIMetaEvent(dword deltaTime,byte metatype);

  /*!
   * \return MIDI_METAEVENT, since this is a channel event
   */
  MIDIEventType type();

  /*!
   * \return The type of the meta event. See MIDI specification
   */
  byte metaType();

  /*!
   * \return This meta event represented as data in a MIDI file
   */
  virtual MIDIDataBuffer data();

  //! Print debug information
  virtual void debug();

private:
  byte _metaType;
};

#endif // MIDIMETAEVENT_H_
