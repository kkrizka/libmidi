#include "MIDIReader.h"

#include <iostream>
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
  cout << "\tNumber of Tracks: " << header->nTracks() << endl;
  cout << "\tTime Division: " << header->timeDivisions() << endl;

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
