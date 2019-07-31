#include "ECHO.h"

int ECHO(char** ar)
{
	int i=1;
	while(ar[i]!=NULL)
	{
		printf("%s ",ar[i]);
		i++;
	}
	printf("\n");
}
