#include "encrypt.h"

char* buf;
double progression;
double remaining_time;

void* encrypt(){
	long lSize;
	unsigned char* buffer=(unsigned char*)malloc(16);;
	size_t result;
	unsigned char input[16];

	fseek (in , 0 , SEEK_END);
	lSize = ftell (in);
	rewind(in);

	if(lSize%(4*Nb)==0){
		time_t tp0=time(NULL);
		fwrite("AESCipheredFile",1,4*Nb,out);
		int i,j;
		long nb_bytes=lSize/(4*Nb);
		for(i=0;i<nb_bytes;i++){
			fread(buffer,1,16,in);
			for(j=0;j<4*Nb;j++){
				input[j]=*(buffer+j);
			}
                     
                        
			Cipher(input,output,w);
                        
                       
                        
			for(j=0;j<4*Nb;j++){
				unsigned char * a=buffer+j;
				*a=output[j];			
			}
			fwrite(buffer,1,4*Nb,out);
			time_t tp=time(NULL);
			progression=100*((double)(i+1))/((double)nb_bytes);
			remaining_time=difftime(tp,tp0)*(100/((double)progression)-1);
			disp_time(remaining_time);
			
		}
	}
	else {
		time_t tp0=time(NULL);
		fwrite("AESCipheredFile",1,4*Nb,out);		
		int i,j;
		long nb_bytes=lSize/16;
		for(i=0;i<nb_bytes;i++){
			fread(buffer,1,16,in);
			for(j=0;j<16;j++){
				input[j]=*(buffer+j);
			}
			Cipher(input,output,w);
			for(j=0;j<16;j++){
				unsigned char* a=buffer+j;
				*a=output[j];
			}
			fwrite(buffer,1,16,out);
			time_t tp=time(NULL);
			progression=100*(double)(i+1)/((double)nb_bytes);
			remaining_time=difftime(tp,tp0)*(100/((double)progression)-1);
			disp_time(remaining_time);
		}
		buffer=(unsigned char*)malloc(lSize%16);
		fread(buffer,1,lSize%16,in);
		for(i=0;i<lSize%16;i++){
			input[i]=*(buffer+i);		
		}
		for(i=lSize%16;i<4*Nb;i++){
			input[i]=4*Nb-lSize%16;		
		}
		Cipher(input,output,w);
		buffer=(unsigned char*)malloc(4*Nb);
		for(i=0;i<4*Nb;i++){
			unsigned char * a=buffer+i;
			*a=output[i];		
		}
		fwrite(buffer,1,4*Nb,out);
	}
	progression=100;
	fclose(in);
	fclose(out);
	free(buffer);
}
