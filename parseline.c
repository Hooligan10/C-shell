#include "parseline.h"

char **parseline(char* line,char delimit[])
{
	int i=0;
	char* token;
	char** tokens=malloc(sizeof(char)*1024);
//	char delimit[]=" \" \";\t\n";
//	char delimit[]="; \n\t";
	token=strtok(line,delimit);
	while(token!=NULL)
	{
		tokens[i]=token;
		i++;
		// if(i>128)
		// {
		// 	tokens=realloc(sizeof(char)*256);
		// 	if(!tokens)
		// 	{
		// 		fprintf(stderr, "realloc error");
		// 	}
		// }
		token=strtok(NULL,delimit);
	}
	tokens[i]=NULL;
	return tokens;

}
