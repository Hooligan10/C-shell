#include "Getenv.h"

int Getenv(char **ar)
{
	if(ar[1]==NULL)
	{
		perror("Argument is missng");
	}
	else
	{
		if(getenv(ar[1])== NULL)
		{
			perror("No such environment variable exists");
		}
		else
			printf("%s\n",getenv(ar[1]));
	}
}