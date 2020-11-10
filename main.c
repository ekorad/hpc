#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

#include "aes.h"
#include "encrypt.h"
#include "decrypt.h"
#include "check_file.h"

FILE* in;				// input file
FILE* out;				// output file
char* in_filename;			// the filename string of the input file
char* out_filename;			// the filename string of the output file
char* action_string;			// the action string that will determine what action should we do : encrypt or decrypt

int main(int argc,char *argv[]){

	if (argc < 3) 
        {
            printf("Numar insuficient de parametrii!\n");
            exit(1);
        }    
        KeyExpansion();			// the key expansion procedure
        in_filename = argv[1];
        out_filename = argv[2];
        
	buf=(char*)malloc(50);		// initialization of the buffer that will hold the remaining time for encryption/decryption as a string
        
	check_file();
	out=fopen(out_filename,"wb");
	if(!strcmp(action_string,"Encrypt")) {
		encrypt();
	}
	if(!strcmp(action_string,"Decrypt")) {
		decrypt();
	}		
	return 0;
}
