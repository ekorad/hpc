#include "check_file.h"

void check_file(){
	progression=0;
	in=fopen(in_filename,"rb");
	fseek (in , 0 , SEEK_END);
	long lSize = ftell (in);
	rewind(in);
	unsigned char * buffer=(unsigned char*)malloc(4*Nb);
	fread((unsigned char*)buffer,1,4*Nb,in);
	rewind(in);
	if(lSize<2){
		printf("Error : Empty File");
                exit(1);
	}
	else if(memcmp(buffer,"AESCipheredFile", 15) == 0){
		action_string="Decrypt";
	}
	else{
		action_string="Encrypt";
	}
}
