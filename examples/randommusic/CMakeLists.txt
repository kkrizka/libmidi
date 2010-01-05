PROJECT(randommusic)

SET(randommusic_SRCS
  main.cpp )

INCLUDE_DIRECTORIES(../../src)
LINK_DIRECTORIES(../../src)


ADD_EXECUTABLE(randommusic ${randommusic_SRCS})
TARGET_LINK_LIBRARIES(randommusic midi)