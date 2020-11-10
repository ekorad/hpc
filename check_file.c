#include "check_file.h"

void check_file(){
	progression=0;
	action_string=(char*)malloc(8);
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
	else if(!strcmp(buffer,"AESCipheredFile")){
		printf("Ready to Decrypt\n");
		action_string="Decrypt";
	}
	else{
		printf("Ready to Encrypt\n");	
		action_string="Encrypt";
	}
}
