#include "MIDIReader.h"

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc,char* argv[])
{
  if(argc!=2)
    {
      cerr << "usage: " << argv[0] << " midifile.mid" << endl;
      return -1;
    }
  MIDIFile mid(argv[1]);
  mid.open();

  MIDIHeader* header=mid.header();

  cout << "Header" << endl;
  cout << "\tFormat Type: " << header->formatType() << endl;
  cout << "\tNumber of Tracks: " << header->numTracks() << endl;
  
  if(header->framesPerSecond())
    {
      cout << "\tFrames Per Second: " << header->framesPerSecond() << endl;
      cout << "\tTicks Per Frame: " << header->ticksPerFrame() << endl;
    }
  else
    cout << "\tTicks Per Beat: " << header->ticksPerBeat() << endl;

  for(int i=0;i<mid.numTracks();i++)
    {
      MIDITrack* track=mid.track(i);
      cout << "Track #" << i+1 << endl;
      
      for(int j=0;j<track->numEvents();j++)
	{
	  MIDIEvent* event=track->event(j);
	  event->debug();
	}
    }

  return 0;
}
