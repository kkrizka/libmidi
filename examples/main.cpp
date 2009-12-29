#include "MIDIFile.h"

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
  return 0;
}
