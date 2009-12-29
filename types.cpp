#include "types.h"

#include <math.h>

#include <iostream>
#include <iomanip>
using namespace std;

int char2num(char c)
{
  int res=(int)c;
  if(res<0) res+=256;
  return res;
}

char num2char(int i)
{
  if(i>=128)
    return (char)(i-256);
  else
    return (char)i;
}

dword byte2dword(byte array[])
{
  dword result=0;
  for(int i=0;i<4;i++) //Double Word has 4 bytes
    {
      result=(result<<8);
      result+=array[i];
    }

  return result;
}

word byte2word(byte array[])
{
  word result=0;
  for(int i=0;i<2;i++) //Word has 2 bytes
    {
      result=(result<<8);
      result+=array[i];
    }

  return result;
}
