#include "types.h"
#include "dictionnaire.h"
#include "compression.h"
#include "decompression.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>



int main(int argc, char * argv[])
{
	FILE * f_e = NULL;
	FILE * f_i = NULL;
	//FILE * f_s = NULL;

	f_e = fopen(argv[1],"r");
	f_i = fopen(argv[2],"w");
	//f_s = fopen(argv[3],"w");

	//compression(f_e,f_i);
	//fclose(f_i);

	f_i = fopen(argv[2],"r");
	decompression(f_e,f_i);

	fclose(f_e);
	fclose(f_i);
	//fclose(f_s);

	return 0;
	
}
