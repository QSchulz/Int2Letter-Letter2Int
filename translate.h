/****************************************************************************/
/* C library for translating a number in french in its value and vice-versa */
/* and managing special cases of french language                            */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

#include <stdio.h>
#include <stdlib.h>

/*Return the french word for the number of ten in the number in parameter (the number is already the number of ten!)*/
char* dizaine(int number);
/*Return the french word for the unit number in parameter*/
char* unite(int number);
/*Return the french word for special cases (i.e., 0 or between 11 and 16)*/
char* special(int number);

#endif
