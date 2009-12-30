#ifndef MIDICHANNELEVENT_H_
#define MIDICHANNELEVENT_H_

#include "MIDIEvent.h"

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
class MIDIChannelEvent : public MIDIEvent
{
public:
  //! Default Constructor
  MIDIChannelEvent();
  //! Copy Constructor
  MIDIChannelEvent(const MIDIChannelEvent& o);
  //! Constructor
  MIDIChannelEvent(dword timeDelta,byte type,int channel,int param1,int param2);

  /*!
   * Type or command that this event represents. See MIDI specification for
   * a complete list of possible values.
   *
   * \return type or command
   */
  byte type();

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

  virtual void debug();

private:
  byte _type;
  int _channel;
  int _param1;
  int _param2;
};

#endif // MIDICHANNELEVENT_H_
