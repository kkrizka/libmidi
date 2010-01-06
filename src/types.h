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

#ifndef TYPES_H_
#define TYPES_H_

//! Will hold at least 32 bits on all platforms
typedef unsigned long dword;
//! Will hold at least 16 bits on all platforms
typedef unsigned int word;
//! Will hold at least 8 bits on all platforms
typedef unsigned char byte; 

//! Converts a char into an unsigned integer
 /*!
 * \param c Input character
 * \return c as an unsigned number. Range is 0 to 255
 */
unsigned int char2num(char c);

//! Converts a an unsigned number into a character
/*!
 * \param i Input number, must be in range 0 to 255
 * \return Character c represented by code c
 */
char num2char(unsigned int i);

//! Concatonates (bitwise) 4 byte-long variables into 1 variable
/*!
 * \param array Array of length 4
 * \return Concatonated array
 */
dword byte2dword(byte array[]);

//! Concatonates 1 variable into 4 byte-long variables
/*!
 * \param var Some variable
 * \return Array of bytes that var was split into
 */
byte* dword2byte(dword var);

 //! Concatonates (bitwise) 2 byte-long variables into 1 variable
 /*!
 * \param array Array of length 2
 * \return Concatonated array
 */
word byte2word(byte array[]);

//! Concatonates 1 variable into 2 byte-long variables
/*!
 * \param var Some variable
 * \return Array of bytes that var was split into
 */
byte* word2byte(word var);



#endif // TYPES_H_
