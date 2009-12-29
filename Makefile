OBJS=main.o MIDIFile.o MIDIChunk.o MIDIHeader.o MIDITrack.o MIDIEvent.o MIDIChannelEvent.o MIDIChannelControllerEvent.o MIDIMetaEvent.o MIDIMetaUnknownEvent.o MIDIMetaTextEvent.o types.o

all: ${OBJS}
	g++ -g -o midireader ${OBJS}

clean:
	rm ${OBJS}