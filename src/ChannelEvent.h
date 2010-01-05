#ifndef MIDICHANNELEVENT_H_
#define MIDICHANNELEVENT_H_

#include "Event.h"

namespace MIDI
{
  //! This class represents channel events
  /*!
   * Channel events are events that are send to the synthesizer.
   *
   * Each channel event has 4 fields:
   * <ul>
   *  <li>Type or command</li>
   *  <li>Channel to apply to</li>
   *  <li>2 data parameters. Each is a maximum of 1 byte in length.</li>
   * </ul>
   */
  class ChannelEvent : public Event
    {
    public:
      //! Default Constructor
      ChannelEvent();
      //! Copy Constructor
      ChannelEvent(const ChannelEvent& o);
      //! Constructor
      ChannelEvent(dword timeDelta,byte command,int channel,int param1,int param2);

      /*!
       * \return MIDI_CHEVENT, since this is a channel event
       */
      EventType type();
      
      /*!
       * Command that this event represents. See MIDI specification for
       * a complete list of possible values.
       *
       * \return type or command
       */
      byte command();
      
      /*!
       * \return Channel number that this event applies to
       */
      int channel();
      
      /*!
       * \return Value of first data parameter
       */
      int param1();
      
      /*!
       * \return Value of second data parameter
       */
      int param2();
      
      /*!
       * \param shorten Whether to not include the command and channel
       * \return This meta event represented as data in a MIDI file
       */
      virtual DataBuffer data(bool shorten=false);
      
      virtual void debug();
      
    private:
      byte _command;
      int _channel;
      int _param1;
      int _param2;
    };
}

#endif // MIDICHANNELEVENT_H_
