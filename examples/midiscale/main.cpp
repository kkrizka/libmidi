#include "MIDIReader.h"

int main(int argc,char* argv[])
{
  MIDIFile file("input.mid");
  file.open();
  file.setPath("output.mid");
  file.write();
}
