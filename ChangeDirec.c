#include "ChangeDirec.h"

int ChangeDirec(char** ar)
{
	if(ar[1]==NULL || (strcmp(ar[1],"~")==0))
	{
//		fprintf(stderr, "Argument to \"cd\" is missing\n");
		chdir(orgdir);
	}
	else
	{
		if(chdir(ar[1])!=0)
		{
			perror("Error:Not a valid directory");
		}
//		tildadirec(cwd,orgdir);
	}
	return 1;
}