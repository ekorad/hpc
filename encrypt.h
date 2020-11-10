#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "aes.h"
#include "disp_time.h"

extern FILE* in;	
extern FILE* out;
extern unsigned char output[16];
extern unsigned char w[4][Nb*(Nr+1)];
extern unsigned char key[16];

void* encrypt();

#endif
