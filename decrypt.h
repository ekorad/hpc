#ifndef DECRYPT_H
#define DECRYPT_H

#include "disp_time.h"
#include "aes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern FILE* in;
extern FILE* out;
extern double progression;
extern double remaining_time;
extern char* buf;
extern unsigned char output[16];
extern unsigned char w[4][Nb*(Nr+1)];
extern unsigned char key[16];

void decrypt();


#endif
