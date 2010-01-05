PROJECT(mididump)

SET(mididump_SRCS
  main.cpp )

INCLUDE_DIRECTORIES(../../src)
LINK_DIRECTORIES(../../src)


ADD_EXECUTABLE(mididump ${mididump_SRCS})
TARGET_LINK_LIBRARIES(mididump midi)