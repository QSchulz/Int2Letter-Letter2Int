/****************************************************************************/
/* C library for multiplying or dividing a number by the nth pow of 1000    */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#ifndef __PUISSANCE_1000_H__
#define __PUISSANCE_1000_H__

#include <stdio.h>
#include <stdlib.h>
/*Multiply the number by puissance1000 pow of 1000*/
/*number the number to be mulitplied*/
/*puissance1000 the pow of 1000 which is needed to multiply the number*/
/*return the multiplied number*/
int multiplied(int number, int puissance1000);
/*Divide the number by puissance1000 pow of 1000*/
/*number the number to be divided*/
/*puissance1000 the pow of 1000 which is needed to divide the number*/
/*return the divided number*/
int divided(int number, int puissance1000);

#endif
