#ifndef DECOMPRESSION_C
#define DECOMPRESSION_C

#include "decompression.h"
#include "types.h"
#include "dictionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

char * char_to_string2(char c)
{
char * chaine;
chaine = malloc(sizeof(char)+1);

sprintf(chaine, "%c%s", c, "\0");
return chaine;
}

int estPresent(Code * i)
{

Liste * courant=tete_liste;
while (courant->next != NULL && courant->c==*i)
{courant=courant->next;}

return courant->c==*i;

}


Code lire(FILE * lefichier,int nombrebit,byte tampon)
{

Code i=0;
fread (&i,1,1,lefichier);
printf("J'ai lu %d.\n",i);
fread (&tampon,1,1,lefichier);
printf("J'ai lu %d.\n",i2);
i=i<<(nombrebit-8);
printf("Le i vaux maintenant %d.\n",i);
i2=i2>>(16-nombrebit);
printf("Le i2 vaux maintenant %d.\n",i2);
i=i|i2;
printf("Le i final est : %d.\n",i);


//fseek(lefichier,-(16-nombrebit),ftell(lefichier));

return i;

}

int binaire_to_decimal(Code i)
{
	int val=0;
	int puissance;
	int mask=0x1;
	int maskCode=i;
	for(puissance=0;puissance<8;puissance++)
	{	
		printf("La valeur du maskCode est : %d\n",maskCode);
		int valeurBit=mask&maskCode;
		printf("La valeur du bit est : %d\n",valeurBit);
		val=val+valeurBit*pow(2.0,(float)puissance);
		printf("La valeur est : %d\n",val);
		maskCode=maskCode>>1;
	}

	return val;
	
}


void decompression(FILE * entree,FILE * sortie)
{
	Code i;
	Code i2;
	char * point= malloc(sizeof(char));
	Sequence w;
	Sequence w1;
	int nb_bit=9;
	int dec;
	int *longueur = malloc(sizeof(int));
	Initialiser();
	i=lire(entree,nb_bit);
	*point=fgetc(entree);
	printf("le code i est %d.\n",i);
	char a=(CodeVersChaine(i,longueur))[0];
	w=char_to_string(a);
	printf("La chaine w est %s\n",w);

	fprintf(sortie,"%s",w);
	printf("Avant le while \n");
	while(!feof(entree))
	{printf("Entrée du while\n");
		//if (i!=EOF){
		i2=lire(entree,nb_bit);
		printf("le code de %c est %d.\n",i2,i2);
		//*point=fgetc(entree);
		printf("La taille de la séquence est %d.\n",strlen(rechercheSeq(i)));
		w1=malloc(strlen(rechercheSeq(dec))*sizeof(char)+sizeof(char));
		if(!estPresent(&i2))
		{
		
		
			w1=CodeVersChaine(i,longueur);				
			sprintf(w1,w1,w);
			}
		else w1=CodeVersChaine(i2,longueur);	

			fprintf(sortie,"%s",w1);
			a=w1[0];
			Inserer(SequenceVersCode(w),SequenceVersCode(&a),NULL);
			if (fin_liste->c>=pow((float)2,(float)nb_bit))
			{
				nb_bit++;
			}			
			w=char_to_string2(a);
			i=i2;
			}
		

	 //}
	printf("Fin du fichier\n");
}
#endif
