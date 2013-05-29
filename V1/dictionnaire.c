#include "types.h"
#include "dictionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

	//Renvoi la Sequence associé au Code passé en paramètre
	Sequence rechercheSeq(Code monCode)
	{
	
			Liste * courant = tete_liste;	
	
			while (courant != NULL && courant->c != monCode)
			{
				courant=courant->next;	
			}

			if (courant==NULL)
			{
				return NULL;
			}

			else {	//printf("La sequence correspondante est %s\n\n",courant->p_s);
				return courant->p_s;
				}
	}


	// Initialise un dictionnaire avec toutes les monoséquences
	void Initialiser() 
	{
			int nb_alloue = 0; 
			char * codeAscii = malloc(sizeof(char));
			*codeAscii=(char) nb_alloue;			
			tete_liste = malloc(sizeof(Liste));
			Liste * courant;
			Liste * suivant;
			Sequence Adr_Seq;
	
			tete_liste->c=nb_alloue;

			Adr_Seq = (char *) malloc(sizeof(char));
			*Adr_Seq = (char) nb_alloue;			
			tete_liste->p_s=Adr_Seq;
			tete_liste->next=NULL;
			courant = tete_liste;
			nb_alloue++;

			while (nb_alloue < 256)
			{
					suivant = malloc(sizeof(Liste));
					suivant->c=nb_alloue;
					Adr_Seq = (char *) malloc(sizeof(char));
					*Adr_Seq = (char) nb_alloue;
					*codeAscii=(char) nb_alloue;										
					suivant->p_s=Adr_Seq;
					courant->next=suivant;
					courant=suivant;	
					nb_alloue++;			
			}
		suivant->next=NULL;
		fin_liste=courant;
	}
	
	// Ajoute la séquence d'octets prefixe.mono, affecte son code
	void Inserer (Code prefixe, Code mono, Code *code)
	{
		Liste * courant;
		Sequence chaine_prefixe = rechercheSeq(prefixe);
		Sequence chaine_mono = rechercheSeq(mono);
		Sequence Adr_Seq = malloc(strlen(chaine_prefixe)*sizeof(char)+strlen(chaine_mono)*sizeof(char));
		sprintf(Adr_Seq,"%s%s",chaine_prefixe, chaine_mono);
		courant=malloc(sizeof(Liste));
		fin_liste->next=courant;
		
		courant->c=fin_liste->c+1;
		courant->p_s=Adr_Seq;
		courant->next=NULL;

		fin_liste=courant;

		*code=courant->c;		

 	}

	void Inserer2 (Sequence sequence)
	{
		Liste * courant;
		courant = malloc(sizeof(Liste));
		
		courant->p_s = sequence;
		courant->c = fin_liste->c+1;
		courant->next = NULL;

		fin_liste->next = courant;
		fin_liste = courant;
	}

	// Renvoie séquence et affecte la longueur associée à code
	Sequence CodeVersChaine (Code code, int *longueur)
	{
	
		*longueur = strlen(rechercheSeq(code));
		return rechercheSeq(code);

	}


	int EstPresent(Code code)
	{
		Liste * courant = tete_liste;

		while (courant!=NULL && courant->c != code)
			courant = courant->next;

		return courant != NULL;
	}

	

	// Renvoie le code associé à séquence
	Code SequenceVersCode (Sequence sequence)
	{
	
			Liste * courant = tete_liste;	
	
			while (courant != NULL && strcmp(courant->p_s,sequence) != 0 )
			{
				courant=courant->next;	
			}

			if (courant==NULL)
			{
				return -1;
			}

			else return courant->c;

	}	

	void affiche_dico()
	{
		Liste * courant = tete_liste;
		while (courant != NULL)
		{

			//printf("La case courante a pour code %d et sa séquence est %s.\n",courant->c,courant->p_s);
			courant=courant->next;
		}
	}
/*int main()
{
	Code * leCode= malloc(sizeof(Code));
	Code monCode;
	int *longueur = malloc(sizeof(int));
	Sequence Adr_Seq= malloc(sizeof(Sequence));

	Initialiser();
	affiche_dico();
	Inserer(66,67,leCode);
	affiche_dico();
	Adr_Seq=CodeVersChaine(256,longueur);
	printf("La taille de la chaine %s est %d.\n",Adr_Seq,*longueur);
	Adr_Seq="DC";
	monCode=SequenceVersCode(Adr_Seq);
	printf("Le code correspondant est %d.\n",monCode);
	return 0;
}*/
