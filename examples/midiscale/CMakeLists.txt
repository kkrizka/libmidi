PROJECT(midiscale)

SET(midiscale_SRCS
  main.cpp )

INCLUDE_DIRECTORIES(../../src)
LINK_DIRECTORIES(../../src)


ADD_EXECUTABLE(midiscale ${midiscale_SRCS})
TARGET_LINK_LIBRARIES(midiscale midi)