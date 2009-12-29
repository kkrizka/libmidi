OBJS=main.o MIDIFile.o MIDIChunk.o MIDIHeader.o MIDITrack.o MIDIEvent.o MIDIChannelEvent.o MIDIChannelControllerEvent.o MIDIMetaEvent.o MIDIMetaGenericEvent.o MIDIMetaTextEvent.o MIDIMetaNumberEvent.o types.o

all: ${OBJS}
	g++ -g -o midireader ${OBJS}

clean:
	rm -f midireader
	rm -f ${OBJS}
	rm -f *~ \#*