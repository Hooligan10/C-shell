#include "readline.h"

char* readline(void)
{
	
	char* buffer=malloc(sizeof(char)*1024);
	int c,position=0;
	if(!buffer)
	{
		fprintf(stderr, "malloc error");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		c=getchar();
		if(c==EOF || c=='\n')
		{
			buffer[position]='\0';
			return buffer;
		}
		else
		{
			buffer[position]=c;
		}
		position++;
		// if(position>1024)
		// {
		// 	buffer=realloc(sizeof(char)*2048);
		// 	if(!buffer)
		// 	{
		// 		fprintf(stderr, "realloc error");
		// 		exit(EXIT_FAILURE);
		// 	}
		// }
		
	}

}