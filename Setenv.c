#include "Setenv.h"

int Setenv(char **ar)
{
	if(ar[1]==NULL)
	{
		perror("Arguments missing");
	}
	else if(ar[3]!=NULL)
	{
		perror("Too many arguments");
	}
	else
	{
		if(ar[2]!=NULL)
		{
			if(setenv(ar[1],ar[2],1)==-1)
			{
				perror("Error found");
			}
		}
		else if(ar[2]==NULL)
		{
			
			if(setenv(ar[1],"",1)==-1)
			{
				perror("Error found");
			}
			
		}
	}
}