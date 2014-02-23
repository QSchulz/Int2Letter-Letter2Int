/****************************************************************************/
/* C library for translating a number in french in its value                */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#ifndef __LETTER_TO_INT_H__
#define __LETTER_TO_INT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translate.h"
#include "puissance1000.h"

/*The word in parameter will be returned in its number version*/
/*number is the word which has to be translated and is between 0 and 999*/
/*return the value for this number*/
int computeCentaine(char* number);
/*The word in parameter will be returned in its number version*/
/*number is the word which has to be translated and is between 0 and 99*/
/*return the value for this number*/
int computeUnderCentaine(char* centaine);
/*The word in parameter will be returned in its number version*/
/*number is the word which has to be translated*/
/*return the value for this number*/
int letter2int(char* number);
#endif
