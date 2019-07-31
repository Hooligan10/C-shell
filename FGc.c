#include "FGc.h"
//#include "main.h"
void handler(int sig)
{
	pid_t pid;
	pid=wait(NULL);
	printf("\nPid %d exited.\n", pid);
}
int FGc(char** ar)
{
	pid_t pid;
	int status;
//	signal(SIGCHLD,handler);
	pid=fork();
	if(pid<0)
	{
		printf("ERROR : forking failed");
	}
	else if(pid==0)
	{
		execvp(*ar,ar);
		printf("ERROR,process failed");
		exit(1);
	}
	else
	{
		if(ar[1]==NULL)
		{
			 waitpid(pid,NULL,0);
			 //{
			 //	perror("waitpid() failed");
			 //	exit(EXIT_FAILURE);
			// }
		}
		else if(strcmp(ar[1],"&")==0)
		{
		//	wait(&status);
		//	if ( WIFEXITED(status))
		//	{
		//		fprintf(stderr,"%s with pid %d exited normally",ar[0],pid);
		//	}
	//		printf("Pid %d exited.\n", pid);
			bg_order[bglen++]=pid;
			bg_processes[pid]=malloc(1024);
			strcpy(bg_processes[pid],ar[0]);
			signal(SIGCHLD,handler);
		}

	}
}
