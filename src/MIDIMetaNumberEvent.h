#ifndef MIDIMETANUMBEREVENT_H_
#define MIDIMETANUMBEREVENT_H_

#include "MIDIMetaEvent.h"

/*!
 * Number events are special events that contains only one large (larger than a byte)
 * number data field
 *
 * These currently include:
 * <ul>
 *  <li>MIDI_METAEVENT_SETTEMPO</li>
 * </ul>
 */
class MIDIMetaNumberEvent : public MIDIMetaEvent
{
public:
  //! Default Constructor
  MIDIMetaNumberEvent();
  //! Copy Constructor
  MIDIMetaNumberEvent(const MIDIMetaNumberEvent& o);
  //! Constructor
  MIDIMetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length);

  /*!
   * \return The number stored in this event
   */
  unsigned int number();

  //! Print debug information
  virtual void debug();

private:
  unsigned int _number;
};

#endif //MIDIMETANUMBEREVENT_H_
