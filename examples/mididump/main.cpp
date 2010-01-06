/*
  Copyright (C) 2010 Karol Krizka <kkrizka@gmail.com>
  
  URL: http://www.krizka.net/projects/libmidi/
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  $Id$
*/

#include "MIDI.h"

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
  MIDI::File mid(argv[1]);
  mid.open();

  MIDI::Header* header=mid.header();

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
      MIDI::Track* track=mid.track(i);
      cout << "Track #" << i+1 << endl;
      
      for(int j=0;j<track->numEvents();j++)
	{
	  MIDI::Event* event=track->event(j);
	  event->debug();
	}
    }

  return 0;
}
