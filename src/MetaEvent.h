#ifndef MIDIMETAEVENT_H_
#define MIDIMETAEVENT_H_

#include "types.h"

#include "Event.h"

namespace MIDI
{
  /*!
   * Meta events are events that are not send to a synchronizer. This
   * class represents an abstract meta event.
   *
   * There are several types of events, each of which is referenced
   * by some meta type. See the MIDI specification for different 
   * meta types.
   */
  class MetaEvent : public Event
  {
  public:
    //! Default constructor
    MetaEvent();
    //! Copy constructor
    MetaEvent(const MetaEvent& o);
    //! Constructor
    MetaEvent(dword deltaTime,byte metatype);
    
    /*!
     * \return MIDI_METAEVENT, since this is a channel event
     */
    EventType type();
    
    /*!
     * \return The type of the meta event. See MIDI specification
     */
    byte metaType();
    
    /*!
     * \return This meta event represented as data in a MIDI file
     */
    virtual DataBuffer data();

    //! Print debug information
    virtual void debug();
    
  private:
    byte _metaType;
  };
}

#endif // MIDIMETAEVENT_H_
