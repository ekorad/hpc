#ifndef CHECK_FILE_H
#define CHECK_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aes.h"

extern char* action_string;
extern FILE* in;
extern char* in_filename;
extern double progression;

void check_file();

#endif
