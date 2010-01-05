#ifndef MIDICHANNELCONTROLLEREVENT_H_
#define MIDICHANNELCONTROLLEREVENT_H_

#include "ChannelEvent.h"

namespace MIDI
{
  /*!
   * Controller events are special events that have a sub type and a value.
   *
   * See the MIDI specification for a complete list of contoller event types.
   */
  class ChannelControllerEvent : public ChannelEvent
  {
  public:
    //! Default Constructor
    ChannelControllerEvent();
    //! Copy Constructor
    ChannelControllerEvent(const ChannelControllerEvent& o);
    //! Constructor
    ChannelControllerEvent(dword deltaTime,int channel,int controllertype,int value);
    
    /*!
     * \return The sub type of this controller event
     */
    int controllerType();
    
    /*!
     * \return Value held by this sub type
     */
    int value();
    
    //! Print debug information
    virtual void debug();
    
  private:
    int _controllertype;
    int _value;
  };
}

#endif // MIDICHANNELCONTROLLEREVENT_H_
