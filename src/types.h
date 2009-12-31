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
 * \param Some variable
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
 * \param Some variable
 * \return Array of bytes that var was split into
 */
byte* word2byte(word var);



#endif // TYPES_H_
