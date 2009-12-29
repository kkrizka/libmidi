#ifndef MIDIFILE_H_
#define MIDIFILE_H_

#include <string>
using namespace std;

#include "MIDIChunk.h"

class MIDIFile
{
public:
  MIDIFile(string path);

  bool open();

protected:
  MIDIChunk* readChunk(ifstream& fh);

private:
  string _path;
};

#endif // MIDIFILE_H_
