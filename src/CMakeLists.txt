PROJECT(libmidi)

SET(libmidi_SRCS
  DataBuffer.cpp
  File.cpp 
  Chunk.cpp  
  Header.cpp
  Track.cpp
  Event.cpp
  ChannelEvent.cpp 
  ChannelControllerEvent.cpp
  MetaEvent.cpp 
  MetaGenericEvent.cpp
  MetaTextEvent.cpp
  MetaNumberEvent.cpp 
  types.cpp )

SET(libmidi_HEADERS
  MIDI.h

  Defines.h

  DataBuffer.h

  File.h 
  Chunk.h  
  Header.h
  Track.h
  Event.h
  ChannelEvent.h 
  ChannelControllerEvent.h
  MetaEvent.h 
  MetaGenericEvent.h
  MetaTextEvent.h
  MetaNumberEvent.h 

  types.h
  )

ADD_LIBRARY(midi SHARED ${libmidi_SRCS})

INSTALL(TARGETS midi
  LIBRARY DESTINATION lib)

INSTALL(FILES ${libmidi_HEADERS}
  DESTINATION include/libmidi)