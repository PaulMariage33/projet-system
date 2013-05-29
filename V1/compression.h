#ifndef COMPRESSION_H
#define COMPRESSION_H

		char * char_to_string(char c);
		char * int_to_string(int i);
		void compression(FILE* f_e, FILE* f_s);
		void decompression(FILE* f_e, FILE* f_s);

#endif
