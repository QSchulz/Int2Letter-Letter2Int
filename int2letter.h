/****************************************************************************/
/* C library for translating number in its french word                      */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#ifndef __INT_TO_LETTER_H__
#define __INT_TO_LETTER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puissance1000.h"
#include "translate.h"

/*Return the french word of a number between 0 and 999 both included*/
/*number is the number to be translated*/
/*return its french translation*/
char* centaine(int number);

/*The number in parameter will be returned in its french version*/
/*number is the number which has to be translated*/
/*return the french word for this number*/
char* int2letter(int number);

#endif
