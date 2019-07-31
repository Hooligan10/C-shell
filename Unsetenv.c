#include "Unsetenv.h"
int Unsetenv(char** ar)
{
	if(ar[1]==NULL)
	{
		perror("Argument missing");
	}
	else
	{
		unsetenv(ar[1]);
	}
}
