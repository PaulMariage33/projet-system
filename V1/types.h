#ifndef TYPES_H
#define TYPES_H

	typedef int Code;
	typedef char * Sequence;

	/*typedef struct
	{
			Code c;
			Sequence s;
			struct Arbre * fg;
			struct Arbre * fd;		
	} Arbre;

	typedef struct
	{
			Code c;
			Sequence s;
	} Couple;*/

	typedef struct Liste Liste;
	struct Liste
	{
			Code c;
			Sequence p_s;
			struct Liste *next;
	};


	//Couple * tab[256];

#endif

