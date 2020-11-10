#ifndef AES_H
#define AES_H

#define Nb 4
#define Nk sizeof(key)/4
#define Nr 6+Nk

typedef unsigned char word[4];
typedef unsigned char state[4][4];

extern unsigned char key[16];

void KeyExpansion();
void Cipher(unsigned char input[4*Nb], unsigned char output[4*Nb],unsigned char w[4][Nb*(Nr+1)]);
void InvCipher(unsigned char input[4*Nb], unsigned char output[4*Nb],unsigned char w[4][Nb*(Nr+1)]);

#endif
