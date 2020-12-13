all:
	g++ -pthread -g -o main main.cpp aes.cpp disp_time.cpp check_file.cpp encrypt.cpp decrypt.cpp -lm
