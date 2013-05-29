#include "types.h"
#include "dictionnaire.h"
#include "compression.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char * char_to_string(char c)
{
		char * chaine;
		chaine = malloc(sizeof(char)+1);

		sprintf(chaine, "%c%s", c, "\0");
		return chaine; 
}

char * int_to_string(int i)
{
		char * chaine;
		chaine = malloc(sizeof(char)+1);

		sprintf(chaine, "%d%s", i, "\0");
		return chaine; 
}

/*void compression(FILE* f_e, FILE* f_s)
{
		Initialiser();
		
		printf("Initialisation : done \n");
		Sequence w = NULL;
		char a;
		Sequence chaine_concat = NULL;
		Code c;
		Code * code_wa = malloc(sizeof(Code));

		w = char_to_string(fgetc(f_e));

		while (!feof(f_e))
		{
				a = fgetc(f_e);
				chaine_concat = malloc(strlen(w)*sizeof(char)+2);
				sprintf(chaine_concat, "%s%c", w, a);

				printf("caca1 : done\n");
				c = SequenceVersCode(chaine_concat);
				printf("caca2 : done\n");

				if (c!=-1) // si (w.a existe dans le dictionnaire) 
				{	
						printf("-----w.a existe dans le dico-----\n");
						printf("caca2bis : done\n");
						w = malloc(strlen(chaine_concat)*sizeof(char)+1);
						printf("caca3 : done\n");
						w = chaine_concat;
						printf("caca4 : done\n");
				}
				else
				{
						printf("-----Existe %d-----\n", tete_liste->c);
						printf("caca5 : done\n");
						Inserer(SequenceVersCode(w),SequenceVersCode(char_to_string(a)),code_wa);
						printf("caca6 : done\n");
						fputs(int_to_string(*code_wa),f_s);
						fputc('.',f_s);
						w = char_to_string(a);
				}
		}
		fputs(int_to_string(SequenceVersCode(w)),f_s);
} */

void compression(FILE* f_e, FILE* f_s)
{
	Initialiser();

	Sequence w = "";
	char c;
	Sequence wc = NULL;
	Code code;
	Code code_w;
	Code * code_wc = malloc(sizeof(Code));

	while (!feof(f_e))
	{
		c = fgetc(f_e);
		
		if (c!= EOF)
		{
			wc = malloc(strlen(w)*sizeof(char)+2);
			sprintf(wc, "%s%c", w, c);
			//printf("w : %s ; c : %c ; wc : %s\n", w, c, wc);
			code = SequenceVersCode(wc);

			if (code!=-1) // si (wc existe dans le dictionnaire) 
			{
				//printf("-----wc : %s existe dans le dico-----\n", wc);
				w = wc;
			}
			else
			{
				//printf("----- Existe -----\n");
				Sequence c_seq = char_to_string(c);
				code_w = SequenceVersCode(w);

				Inserer(code_w,SequenceVersCode(c_seq),code_wc);
				/*if (code_w < 256)
					fputc(code_w,f_s);
				else
				{*/
					fputc(code_w,f_s);
					//fputc('.',f_s);
					/*fputc('<',f_s);
					fputs(int_to_string(code_w),f_s);
					fputc('>',f_s);*/
				//}

				w = c_seq;
			}
		}
	}
	fputs(w,f_s);
}

/*void decompression(FILE* f_e, FILE* f_s)
{
	Initialiser();

	char c;
	Sequence entree ;
	Sequence chaine_concat;

	Sequence w;

	c = fgetc(f_e);
	fputc(c,f_s);
	w = char_to_string(c);

	while (!feof(f_e))
	{	
		printf("here");
		c = fgetc(f_e);

		if (c>255 && EstPresent(c))
			entree = rechercheSeq(c);
		else if (c>255 && !EstPresent(c))
		{
			entree = malloc(strlen(w)*sizeof(char)+2);
			sprintf(entree, "%s%c", w, w[0]);
		}
		else
			entree = char_to_string(c);

		fputs(entree,f_s);
		chaine_concat = malloc(strlen(w)*sizeof(char)+sizeof(char)+1);
		sprintf(chaine_concat,"%s%c",w,entree[0]);
		Inserer2(chaine_concat);	
		w = entree;
		
	}	
}	*/
