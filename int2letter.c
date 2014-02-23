/****************************************************************************/
/* C library for translating number in its french word                      */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#include "int2letter.h"

/*The number in parameter will be returned in its french version*/
/*number is the number which has to be translated*/
/*return the french word for this number*/
char* int2letter(int number){
	/*Retrieve the pow of 1000 of the number (e.g., 5 is 0, 1200 is 1, 1 512 124 is 2)*/
	int puissance1000 = 0;
	int numbercpy = number;
	char* words[3]={"mille", "million", "milliard"};
	char *word = NULL, *temp = NULL;
	/*tempnb will store the multiple of the nth pow of 1000*/
	int tempnb;
	if(number==0)
	{s
		word = malloc (sizeof(char)*(strlen("zero")+1));
		strcpy(word, special(0));
		return word;
	}
	word = malloc(sizeof(char));
	strcpy(word, "\0");
	/*Find which pow of 1000 it is (is it a thousand, a million or a billion?)*/
	while(divided(number, puissance1000)>0)
		puissance1000++;
	puissance1000--;
	while(puissance1000>=0)
	{
		/*Store the multiple of the puissance1000th pow of 1000 (e.g., 23 456 gives 23)*/
		tempnb = divided(numbercpy, puissance1000);
		/*Check if this number is not 1 and the pow of 1000 is not 1 (e.g., numbers like 1xxx) => in french we say "mille" and not "un mille")*/
		if (!(puissance1000==1 && tempnb==1))
		{
			/*Retrieve the number of hundreads in french in the multiple of the puissance1000th pow of 1000 (e.g., 923 456 gives "neuf"*/
			temp = centaine(tempnb);
			word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+3));
			strcat(word, temp);
			strcat(word, " ");
			free(temp);
			temp = NULL;
		}
		/*Check if the number to be translated at this time is strictly greater than 999*/
		if (puissance1000>0)
		{	
			word = realloc(word, sizeof(char)*(strlen(word)+strlen(words[puissance1000-1])+1));
			/*We add at the end of the word a suffixe representing the puissance1000th pow of 1000 (e.g., 123 456 789 gives "million")*/
			strcat(word, words[puissance1000-1]);
			word = realloc(word, sizeof(char)*(strlen(word)+2));
			strcat(word, " ");
		}
		/*Only keep the untranslated part of the number (e.g., 15 236. We have done operations on 15 and added the suffixe to it then we only want to translate 236*/
		numbercpy = numbercpy - multiplied(tempnb, puissance1000);
		puissance1000--;
	}
	return word;
}
/*Return the french word of a number between 0 and 999 both included*/
/*number is the number to be translated*/
/*return its french translation*/
char* centaine(int number){
	char* temp = NULL;
	char* word = malloc(sizeof(char));	
	int dizainenb;
	strcpy(word, "\0");
	if (number/100!=0)
	{
		/*Check if the number of hundreads is not 1 because in french we say "cent" and not "un cent"*/
		if (number/100>1)
		{
			/*Retrieve the number of hundreads*/
			temp = unite(number/100);
			word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+2));
			strcat(word, temp);
			strcat(word, " ");
		}
		word = realloc(word, sizeof(char)*(strlen(word)+strlen("cent ")+1));
		/*We add at the end of the word a suffixe representing the word "hundread" in french*/
		strcat(word, "cent ");
		/*Only keep the untranslated part of the number*/
		number=number-number/100*100;
	}
	dizainenb = number/10;
	/*Check if the number is between 11 and 16 because we say "onze", "douze", "treize", "quatorze", "quinze" and "seize"*/
	if (dizainenb==1 && number%10>=1 && number%10<=6)
	{
		temp = special(number);
		word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+1));
		strcat(word, temp);	
	}
	/*Check if the number is between 70 and 79 or between 90 and 99 because in french we say "soixante-dix-neuf" (i.e. 60+19 instead of 70+9)*/
	else if (dizainenb==7 || dizainenb==9)
	{
		temp = dizaine(dizainenb-1);
		word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+2));
		strcat(word, temp);
		strcat(word, " ");
		/*Check if the number is 71 in this case we say "soixante-et-onze" and not "soixante-onze"*/
		if (dizainenb == 7 && number%10==1)
		{
			word = realloc(word, sizeof(char)*(strlen(word)+strlen("et ")+1));
			strcat(word, "et ");	
		}
		/*Check if we are between 71 and 76 or between 91 and 96 because we translate 75 by 60+15 and a number between 11 and 16 is special*/
		if (number%10>=1 && number%10<=6)
		{
			temp = special(number-(dizainenb-1)*10);
			word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+1));
			strcat(word, temp);		
		}
		/*Check if we are not in a special case*/
		else
		{
			/*We add the untranslated part of the number*/
			temp = centaine(number-(dizainenb-1)*10);
			word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+1));
			strcat(word, temp);
		}
	}
	/*Normal case (i.e. neither between 11 and 16 nor between 70 and 79 nor between 90 and 99*/
	else
	{
		/*Retrieve the number of ten*/
		temp = dizaine(number/10);
		word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+1));
		strcat(word, temp);
		/*Check if we have not a multiple of 10*/
		if (number/10>=1 && number-number/10*10!=0)
		{
			word = realloc(word, sizeof(char)*(strlen(word)+2));
			strcat(word, " ");
		}
		/*Check if the number of ten is a multiple (greater than 2) of 10 and the unit number is one because in french we say for 41 "quarante-et-un" and not "quarante-un"*/
		if(number/10>=2 && number%10==1)
		{
			word = realloc(word, sizeof(char)*(strlen(word)+strlen("et un")+1));
			strcat(word, "et un");
		}
		else
		{
			temp = unite(number%10);
			word = realloc(word, sizeof(char)*(strlen(word)+strlen(temp)+1));
			strcat(word, temp);
		}
	}
	return word;
}
