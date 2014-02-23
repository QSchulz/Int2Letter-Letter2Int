/****************************************************************************/
/* C library for translating a number in french in its value and vice-versa */
/* and managing special cases of french language                            */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#include "translate.h"
/*Return the french word for the number of ten in the number in parameter (the number is already the number of ten!)*/
char* dizaine(int number){
	char* dizaine[10] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante dix", "quatre vingt", "quatre vingt dix"};
	return dizaine[number%10];
}
/*Return the french word for the unit number in parameter*/
char* unite(int number){
	char* unite[10] = {"", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
	return unite[number%10];
}
/*Return the french word for special cases (i.e., 0 or between 11 and 16)*/
char* special(int number){
	switch (number){
		case 0: return "zero";break;
		case 11: return "onze"; break;
		case 12: return "douze"; break;
		case 13: return "treize"; break;
		case 14: return "quatorze"; break;
		case 15: return "quinze"; break;
		case 16: return "seize";break;
		default: printf("Error or unknown value for %d\n", number); return NULL;
	}
}
