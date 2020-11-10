#include "decrypt.h"

void* decrypt(){
	long lSize;
	unsigned char* buffer=(unsigned char*)malloc(16);
	unsigned char input[16];

	fseek (in , 0 , SEEK_END);
	lSize = ftell (in);
	rewind(in);

	fread((unsigned char*)buffer,1,4*Nb,in);

	time_t tp0=time(NULL);
	int i,j;
	long nb_bytes=lSize/16-1;
	for(i=0;i<nb_bytes-1;i++){
		fread(buffer,1,4*Nb,in);
		for(j=0;j<4*Nb;j++){
			input[j]=*(buffer+j);
		}
		InvCipher(input,output,w);
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
	fread(buffer,1,4*Nb,in);
	for(j=0;j<4*Nb;j++){
		input[j]=*(buffer+j);
	}
	InvCipher(input,output,w);
	for(j=4*Nb-1;output[j]==output[j-1];j--);
	if( j==4*Nb-1 && output[j]==1){
		buffer=(unsigned char*)malloc(4*Nb-1);
		for(i=0;i<4*Nb-1;i++){
			unsigned char * a=buffer+i;
			*a=output[i];
		}
		fwrite(buffer,1,4*Nb-1,out);
	}
	else if ( (j!=4*Nb-1) && (output[j]==4*Nb-j) ){
		buffer=(unsigned char *)malloc(j);
		for(i=0;i<j;i++){
			unsigned char * a=buffer+i;
			*a=output[i];
		}
		fwrite(buffer,1,j,out);					
	}
	else {
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
