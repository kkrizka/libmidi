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
