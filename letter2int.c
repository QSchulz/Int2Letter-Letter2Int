/****************************************************************************/
/* C library for translating a number in french in its value                */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/


#include "letter2int.h"

/*The word in parameter will be returned in its number version*/
/*number is the word which has to be translated*/
/*return the value for this number*/
int letter2int(char* number){
	char* words[3]={"mille", "million", "milliard"};
	char *test, *temp;
	/*Represent the i in ith pow of 1000*/
	int i=2;
	int tmp;
	/*Check if the word contains "milliard"*/
	test = strstr(number, words[i]);
	/*Loop until we have the word "milliard", "million" or "mille" in the word*/
	while(test==NULL && i>0)
	{
		--i;
		test = strstr(number, words[i]);	
	}
	/*No occurence for "milliard", "million" or "mille" in the word*/
	if (test==NULL)
		/*The number is strictly lesser than 1000*/
		return computeCentaine(number);
	/*Check if there is nothing before the occurence of the word found*/
	if (strlen(number)==strlen(test))
		return multiplied(1, i+1)+letter2int(&test[strlen(words[i])]);
	/*Store what is before the occurence*/
	temp = malloc (sizeof(char)*(strlen(number)-strlen(test)+1));
	strcpy(temp, "\0");
	strncat(temp, number, strlen(number)-strlen(test));
	strcat(temp, "\0");
	/*Translate the word before the occurence in a number, multiply itself by the (i+1)th pow of 1000
	/*and recursively call the same function on the rest of the word after deleting the occurence of the word*/
	tmp = multiplied(computeCentaine(temp), i+1)+letter2int(&test[strlen(words[i])+1]);
	free(temp);
	temp = NULL;
	return tmp;
}
/*The word in parameter will be returned in its number version*/
/*number is the word which has to be translated and is between 0 and 999*/
/*return the value for this number*/
int computeCentaine(char* number){
	char* test;
	char* temp;
	int tmp;
	/*Check if the word contains the word "cent"*/
	test = strstr(number, "cent");
	if (test!=NULL)
	{
		/*Check if there is nothing or a space before "cent" */
		if (strlen(number)==strlen(test)+1 || strlen(number)==strlen(test))	
			return 100+computeUnderCentaine(&test[strlen("cent")]);
		temp = malloc (sizeof(char)*(strlen(number)-strlen(test)+1));
		strcpy(temp, "\0");
		strncat(temp, number, strlen(number)-strlen(test));
		strcat(temp, "\0");
		/*On ajoute au nombre temporaire tmp la valeur des unités des centaines multiplié par 100 et la valeur du reste du nombre (après le mot "cent");*/
		/*Multiply the number found by 100 and find the number for the untranslated part*/
		tmp = computeUnderCentaine(temp)*100+computeUnderCentaine(&test[strlen("cent")]);
		free(temp);
		temp = NULL;
		return tmp;
	}
	/*There is no word "cent", we only deal with multiple of ten or unit number*/
	return computeUnderCentaine(number);
}
/*The word in parameter will be returned in its number version*/
/*number is the word which has to be translated and is between 0 and 99*/
/*return the value for this number*/
int computeUnderCentaine(char* centaine){
	int i=1;
	const int specialnb[8]={0,11,12,13,14,15,16};
	char* test = malloc(sizeof (char)*(strlen(centaine)+1));
	strcpy(test, centaine);
	/*Find the next space which represents separation between numbers*/
	test = strtok(test, " ");
	if (test==NULL)
		/*Means no other numbers*/
		return 0;
	if (strcmp(test, "et")==0)
		/*In some special case, we have the word "et" which means nothing in numbers*/
		return computeUnderCentaine(strtok(NULL, " "));
	if (strstr(centaine, "quatre vingt")!=NULL)
		return 80+computeUnderCentaine(&centaine[strlen("quatre vingt")+1]);
	/*Find the multiple of ten thanks to its french translation*/
	while(i<=6 && strcmp(test, dizaine(i))!=0)
		++i;
	/*The multiple of ten is found*/
	if (i<=6)
	{
		if (strlen(centaine)> strlen(test))
			return i*10+computeUnderCentaine(&centaine[strlen(test)+1]);
		/*No other words, it is just a multiple of ten*/
		return i*10;
	}
	/*No multiple of ten found: special case (between 11 and 16) or between 0 and 10*/
	i=0;
	while(i<7 && strcmp(test, special(specialnb[i]))!=0)
		++i;
	if (i<7)
		return specialnb[i];	
	i=1;
	while(i<10 && strcmp(test, unite(i))!=0)
		++i;
	if (i<10)
		return i;
	return 1;
}
