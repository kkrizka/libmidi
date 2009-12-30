#ifndef MIDIMETAGENERICEVENT_H_
#define MIDIMETAGENERICEVENT_H_

#include "types.h"

#include "MIDIMetaEvent.h"


/*!
 * This class represents a generic meta event.
 *
 * A generic meta event contains byte long data that can be accessed by some index.
 *
 * This represents all events not represented by specific classes.
 */
class MIDIMetaGenericEvent : public MIDIMetaEvent
{
public:
  //! Default constructor
  MIDIMetaGenericEvent();
  //! Copy constructor
  MIDIMetaGenericEvent(const MIDIMetaGenericEvent& o);
  //! Constructor
  MIDIMetaGenericEvent(dword deltaTime,byte type,byte data[],int dataLength);

  /*!
   * \return Number of data fields stored in this event
   */
  int dataLength();

  /*!
   * Allows access to data as if it were stored as a signed integer.
   *
   * \param id The id of the data
   * \return The value of the data
   */
  int paramInt(int id);

  /*!
   * Allows access to data as if it were stores as an unsigned integer.
   *
   * \param id The id of the data
   * \return The value of the data
   */   
  unsigned int paramUInt(int id);

  //! Prints debug information
  virtual void debug();

private:
  byte* _data;
  int _dataLength;
};

#endif // MIDIMETAGENERICEVENT_H_
