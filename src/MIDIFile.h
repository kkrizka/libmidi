#ifndef MIDIFILE_H_
#define MIDIFILE_H_

#include <vector>
#include <string>
using namespace std;

#include "MIDIChunk.h"

#include "MIDIHeader.h"
#include "MIDITrack.h"

class MIDIFile
{
public:
  MIDIFile(string path);

  bool open();

  MIDIHeader* header();
  MIDITrack* track(unsigned int id);

  unsigned int numTracks();

protected:
  MIDIChunk* readChunk(ifstream& fh);

private:
  string _path;

  MIDIHeader *_header;
  vector<MIDITrack*> _tracks;
};

#endif // MIDIFILE_H_
