#ifndef MIDIMETATEXTEVENT_H_
#define MIDIMETATEXTEVENT_H_

#include "MetaEvent.h"

#include <string>
using namespace std;

namespace MIDI
{
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
  class MetaTextEvent : public MetaEvent
  {
  public:
    //! Default Constructor
    MetaTextEvent();
    //! Copy Constructor
    MetaTextEvent(const MetaTextEvent& o);
    //! Constructor
    MetaTextEvent(dword deltaTime,byte metaType,byte data[],dword length);
    
    /*!
     * \return The text of this event
     */
    string text();
    
    /*!
     * \return This meta text event represented as data in a MIDI file
     */
    virtual DataBuffer data();
    
    //! Print debug information
    virtual void debug();
    
  private:
    string _text;
  };
}

#endif //MIDIMETATEXTEVENT_H_
