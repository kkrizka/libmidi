#ifndef MIDIMETANUMBEREVENT_H_
#define MIDIMETANUMBEREVENT_H_

#include "MetaEvent.h"

namespace MIDI
{
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
  class MetaNumberEvent : public MetaEvent
  {
  public:
    //! Default Constructor
    MetaNumberEvent();
    //! Copy Constructor
    MetaNumberEvent(const MetaNumberEvent& o);
    //! Constructor
    MetaNumberEvent(dword deltaTime,byte metaType,dword length,unsigned int value=0);
    //! Constructor
    MetaNumberEvent(dword deltaTime,byte metaType,byte data[],dword length);
    
    /*!
     * \return The number stored in this event
     */
    unsigned int number();
    
    /*!
     * The number is stored in the same length string as it came in.
     *
     * \return This meta number event represented as data in a MIDI file
     */
    virtual DataBuffer data();
    
    //! Print debug information
    virtual void debug();
    
  private:
    unsigned int _number;
    
    dword _length;
  };
}

#endif //MIDIMETANUMBEREVENT_H_
