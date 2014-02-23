/****************************************************************************/
/* C library for translating a number in french in its value and vice-versa */
/* Written by SCHULZ Quentin, quentin.schulz@utbm.fr , June 2013            */
/****************************************************************************/

#include "letter2int.h"
#include "int2letter.h"

int main (int argc, char** argv){
	char* line = malloc(sizeof(char)*200); 
	char* temp = NULL;
	FILE *fileRead, *fileWrite;
	char answer;
	int number =0;
	if(argc!=3)
	{
		puts("Il n'y a pas 2 paramètres");
		puts("Vous devez entrer en premier le nom du fichier avec les chiffres avant l'exécution du programme");
		puts("puis en deuxième le nom du fichier où seront stockés les résultats");
		puts("********************");
		puts("./main [fichier_1] [resultat_1]");
		exit(EXIT_FAILURE);
	}
	fileRead = fopen(argv[1], "r+");
	if (fileRead!=NULL)
	{
		fileWrite = fopen(argv[2], "w+");
		while(fgets(line, 200, fileRead)!=NULL)
		{
			/*Delete the "\n" at the end of each line*/
			temp = malloc(sizeof(char)*(strlen(line)+1));
			strcpy(temp, line);
			if (line[strlen(line)-1]=='\n')
				strtok(temp, "\n");
			/*Check if the string is a number or a word (if it's a word, atoi return 0)*/
			number = atoi(temp);
			if (strcmp(temp, "0")!=0 && number==0)
				fprintf(fileWrite,"%d\n",letter2int(temp));
			else
			{
				free(temp);
				temp = NULL;
				temp = int2letter(number);
				fprintf(fileWrite,"%s\n", temp);
			}
			free(temp);
			temp=NULL;
		}
		free(line);
		line = NULL;
		fclose(fileWrite);
		fclose(fileRead);
	}
	else
		exit(EXIT_FAILURE);


	puts("Do you want to print the result file? (Y/n)");
	scanf("%c", &answer);
	if (answer=='Y' || answer=='y')
	{
		printf("********%s********\n", argv[2]);
		line = malloc(sizeof(char)*(strlen("cat ./")+strlen(argv[2])+1));
		strcpy(line, "cat ./");
		strcat(line, argv[2]);
		strcat(line, "\0");
		system(line);
		puts("");
		free(line);
		line = NULL;
	}
	return 0;
}

