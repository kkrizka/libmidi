#ifndef MIDIMETANUMBEREVENT_H_
#define MIDIMETANUMBEREVENT_H_

#include "MIDIMetaEvent.h"

/*!
 * Number events are special events that contains only one large (larger than a byte)
 * number data field.
 *
 * These events are always stored in fixed-length strings
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
  MIDIMetaNumberEvent(dword deltaTime,byte metaType,dword length,unsigned int value=0);
  //! Constructor
  MIDIMetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length);

  /*!
   * \return The number stored in this event
   */
  unsigned int number();

  /*!
   * The number is stored in the same length string as it came in.
   *
   * \return This meta number event represented as data in a MIDI file
   */
  virtual MIDIDataBuffer data();

  //! Print debug information
  virtual void debug();

private:
  unsigned int _number;

  dword _length;
};

#endif //MIDIMETANUMBEREVENT_H_
