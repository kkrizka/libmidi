#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned long dword; // Will hold at least 32 bits on all platforms
typedef unsigned int word; // Will hold at least 16 bits on all platforms
typedef unsigned char byte; // character is a byte, unsgined will make it range from 0-255

unsigned int char2num(char c);
char num2char(unsigned int i);

dword byte2dword(byte array[]);
word byte2word(byte array[]);

#endif // TYPES_H_
