#include "types.h"

#include <math.h>

#include <iostream>
#include <iomanip>
using namespace std;

unsigned int char2num(char c)
{
  int res=(int)c;
  if(res<0) res+=256;
  return res;
}

char num2char(unsigned int i)
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

byte* dword2byte(dword var)
{
  byte* result=new byte[4];
  for(int i=3;i>=0;i--)
    {
      result[i]=var & 0x000000FF;
      var=(var>>8);
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

byte* word2byte(word var)
{
  byte* result=new byte[2];
  for(int i=1;i>=0;i--)
    {
      result[i]=var & 0x00FF;
      var=(var>>8);
    }
  return result;
}
