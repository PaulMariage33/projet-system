#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

	#include <stdio.h>

	//Arbre * dictionnaire;
	Liste * tete_liste;
	Liste * fin_liste;

	// Initialise un dictionnaire avec toutes les monoséquences
	void Initialiser();
	
	// Ajoute la séquence d'octets prefixe.mono, affecte son code
	void Inserer (Code prefixe, Code mono, Code *code);
	
	void Inserer2 (Sequence sequence);

	int EstPresent (Code code);

	//Renvoi la Sequence associé au Code passé en paramètre
	Sequence rechercheSeq(Code monCode);

	// Renvoie séquence et affecte la longueur associée à code
	Sequence CodeVersChaine (Code code, int *longueur);

	// Renvoie le code associé à séquence
	Code SequenceVersCode (Sequence sequence);

#endif
