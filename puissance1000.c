/****************************************************************************/
/* C library for multiplying or dividing a number by the nth pow of 1000    */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#include "puissance1000.h"
int operate(int number, int puissance1000, int minusOrPlus);
/*Multiply the number by puissance1000 pow of 1000*/
/*number the number to be mulitplied*/
/*puissance1000 the pow of 1000 which is needed to multiply the number*/
/*return the multiplied number*/
int multiplied(int number, int puissance1000){
	return operate(number, puissance1000, 1);
}
/*Divide the number by puissance1000 pow of 1000*/
/*number the number to be divided*/
/*puissance1000 the pow of 1000 which is needed to divide the number*/
/*return the divided number*/
int divided(int number, int puissance1000){
	return operate(number, puissance1000, -1);
}
int operate(int number, int puissance1000, int minusOrPlus){
	while(puissance1000>0)
	{
		if (minusOrPlus>0)
			number*=1000;
		else
			number/=1000;
		puissance1000--;
	}
	return number;
}
