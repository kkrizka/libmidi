#ifndef MIDIMETATEXTEVENT_H_
#define MIDIMETATEXTEVENT_H_

#include "MIDIMetaEvent.h"

#include <string>
using namespace std;

/*!
 * Text events are special events that contains only one text data field
 *
 * These currently include:
 * <ul>
 *  <li>MIDI_METAEVENT_TEXT</li>
 *  <li>MIDI_METAEVENT_COPYRIGHT</li>
 *  <li>MIDI_METAEVENT_TRACKNAME</li>
 *  <li>MIDI_METAEVENT_MAKER</li>
 * </ul>
 */
class MIDIMetaTextEvent : public MIDIMetaEvent
{
public:
  //! Default Constructor
  MIDIMetaTextEvent();
  //! Copy Constructor
  MIDIMetaTextEvent(const MIDIMetaTextEvent& o);
  //! Constructor
  MIDIMetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length);

  /*!
   * \return The text of this event
   */
  string text();

  //! Print debug information
  virtual void debug();

private:
  string _text;
};

#endif //MIDIMETATEXTEVENT_H_
