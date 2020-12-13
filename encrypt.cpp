#include "encrypt.h"

#include <vector>
#include <thread>

#define CHUNK 200000

int num_threads = 1;

char* buf;
double progression;
double remaining_time;

std::vector<std::thread> threads;

void thread_func(int tid, unsigned char *buffer, int len) {
	unsigned char input[16];
	unsigned char output[16];

	int n = len / num_threads;

	if (tid == num_threads - 1) {
		n += len % num_threads;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4 * Nb; j++) {
			input[j] = *(buffer + tid * 16 * (len / num_threads) + 16 * i + j);
		}

		Cipher(input, output, w);

		for (int j = 0; j < 4 * Nb; j++) {
			unsigned char *addr = buffer + tid * 16 * (len / num_threads) + 16 * i + j;
			*addr = output[j];
		}
	}
}

void encrypt(int nthreads){
	num_threads = nthreads;
	long lSize;
	unsigned char* buffer = (unsigned char*)malloc(16 * CHUNK);

	fseek (in , 0 , SEEK_END);
	lSize = ftell (in);
	rewind(in);

	fwrite("AESCipheredFile",1,4*Nb,out);

	long n_div = lSize / (16 * CHUNK);
	long n_mod = lSize % (16 * CHUNK);

	for (long pas = 0; pas <= n_div; pas++) {
		int len = CHUNK;
		if (pas == n_div) {
			if (n_mod == 0) break;
			len = n_mod / 16;
		}

		fread(buffer, 1, 16 * len, in);

		for (int tid = 0; tid < num_threads; tid++) {
			threads.push_back(std::thread(thread_func, tid, buffer, len));
		}

		for (auto& thread : threads) {
			thread.join();
		}

		threads.clear();

		fwrite(buffer, 1, 16 * len, out);
	}

	if (lSize % (4 * Nb) != 0) {

		unsigned char input[16];
		unsigned char output[16];

		buffer = (unsigned char*)malloc(lSize % 16);
		fread(buffer, 1, lSize % 16, in);
		for (int i = 0; i < lSize % 16; i++) {
			input[i] = *(buffer + i);
		}
		for (int i = lSize % 16; i < 4 * Nb; i++) {
			input[i] = 4 * Nb - lSize % 16;
		}
		Cipher(input, output, w);
		buffer = (unsigned char*)malloc(4 * Nb);
		for (int i = 0; i < 4 * Nb; i++) {
			unsigned char * a = buffer + i;
			*a = output[i];
		}
		fwrite(buffer, 1, 4 * Nb, out);
	}

	progression=100;
	fclose(in);
	fclose(out);
	free(buffer);
}
