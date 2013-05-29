#include "decompression.h"

char * char_to_string(char c)
{
char * chaine;
chaine = malloc(sizeof(char)+1);

sprintf(chaine, "%c%s", c, "\0");
return chaine;
}


void decompression(FILE *entree,FILE *sortie)
{
	Code * i=malloc(sizeof(Code));
	Code * i2= malloc(sizeof(Code));
	char point= malloc(sizeof(char));
	Sequence w,w1;
	w=malloc(sizeof(Sequence));
	w1=malloc(sizeof(Sequence));
	char a;
	int *longueur = malloc(sizeof(int));
	Initialiser();
	fscanf(entree,"%d",i);
	fscanf(entree,"%c",point);
	a=CodeVersChaine(i,NULL);
	w=char_to_string(a);


	fprintf(sortie,"%s",w);

	while(!feof(entree))
	{
		fscanf(entree,"%d",i2);
		fscanf(entree,"%c",point);
		if(!estPresent(i2,tete_liste))
		{
		
		w1=CodeVersChaine(i,longueur);				
		sprintf(w1,w1,w);
		}
		else w1=CodeVersChaine(i2,longueur);	

		fprintf(sortie,"%s",w1);
		a=w1[0];
		Inserer(SequenceVersCode(w),SequenceVersCode(a),NULL);
		w=char_to_string(a);
		i=i2;
		

	 }

}

