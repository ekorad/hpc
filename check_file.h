#ifndef CHECK_FILE_H
#define CHECK_FILE_H

#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aes.h"

extern std::string action_string;
extern FILE* in;
extern char* in_filename;
extern double progression;

void check_file();

#endif
