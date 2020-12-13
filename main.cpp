#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <string>
#include <chrono>
#include <iostream>

#include "aes.h"
#include "encrypt.h"
#include "decrypt.h"
#include "check_file.h"

FILE* in;				// input file
FILE* out;				// output file
char* in_filename;			// the filename string of the input file
char* out_filename;			// the filename string of the output file
std::string action_string;			// the action string that will determine what action should we do : encrypt or decrypt

struct separate_thousands : std::numpunct<char> {
	char_type do_thousands_sep() const override { return '.'; }
	string_type do_grouping() const override { return "\3"; }
};

int main(int argc,char *argv[]){

	if (argc < 4) 
        {
            printf("Numar insuficient de parametrii!\n");
            exit(1);
        }    
        KeyExpansion();			// the key expansion procedure
        in_filename = argv[1];
        out_filename = argv[2];
		
		int num_threads = atoi(argv[4]);
        
	buf=(char*)malloc(50);		// initialization of the buffer that will hold the remaining time for encryption/decryption as a string
        
	check_file();
	out=fopen(out_filename,"wb");

	auto start = std::chrono::high_resolution_clock::now();

	if(action_string == "Encrypt") {
		encrypt(num_threads);
	}
	else if(action_string == "Decrypt") {
		decrypt();
	}	

	auto thousands = std::make_unique<separate_thousands>();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout.imbue(std::locale(std::cout.getloc(), thousands.release()));
	std::cout << num_threads << "," << duration.count() << std::endl;

	return 0;
}
