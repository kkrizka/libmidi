PROJECT(libmidireader)

SET(libmidireader_SRCS
  MIDIFile.cpp 
  MIDIChunk.cpp  
  MIDIHeader.cpp
  MIDITrack.cpp
  MIDIEvent.cpp
  MIDIChannelEvent.cpp 
  MIDIChannelControllerEvent.cpp
  MIDIMetaEvent.cpp 
  MIDIMetaGenericEvent.cpp
  MIDIMetaTextEvent.cpp
  MIDIMetaNumberEvent.cpp 
  types.cpp )

SET(libmidireader_HEADERS
  MIDIReader.h

  MIDIDefines.h

  MIDIFile.h 
  MIDIChunk.h  
  MIDIHeader.h
  MIDITrack.h
  MIDIEvent.h
  MIDIChannelEvent.h 
  MIDIChannelControllerEvent.h
  MIDIMetaEvent.h 
  MIDIMetaGenericEvent.h
  MIDIMetaTextEvent.h
  MIDIMetaNumberEvent.h 

  types.h
  )

ADD_LIBRARY(midireader SHARED ${libmidireader_SRCS})

INSTALL(TARGETS midireader
  LIBRARY DESTINATION lib)

INSTALL(FILES ${libmidireader_HEADERS}
  DESTINATION include/libmidireader)