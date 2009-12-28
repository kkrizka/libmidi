#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned long dword; // Will hold at least 32 bits on all platforms
typedef unsigned int word; // Will hold at least 16 bits on all platforms

int char2num(char c);
char num2char(int i);

dword char2dword(char array[]);
word char2word(char array[]);

#endif // TYPES_H_
