#include "all.h"
#include "readline.h"
#include "parseline.h"
#include "execute.h"
#include "FGc.h"
#include "LS.h"
#include "LSa.h"
#include "LSla.h"
#include "LSl.h"
#include "ECHO.h"
#include "PWD.h"
#include "ChangeDirec.h"
#include "tildadirec.h"
#include "pinfo.h"
#include "Piping.h"
#include "Redirect.h"
#include "Setenv.h"
#include "Getenv.h"
#include "Unsetenv.h"
//#include "all.h"
void sigintHandler(int sig_num)
{
    //signal(SIGINT, sigintHandler);

	fflush(stdout);
}	


int main(int argc,char** argv)
{
	bglen =0;
	struct utsname buffer;
	char* line;
	char** ar;
	char** tr;
	int status,i=0;
	char cwd[1024];
	char host[1024];
	char tildirec[1024];
//	char orgdir[1024];
	signal(SIGINT, sigintHandler);
	signal(SIGQUIT, sigintHandler);
	signal(SIGTSTP, sigintHandler);
	errno = 0;
   	if (uname(&buffer) != 0)
   	{
      perror("uname");
      exit(EXIT_FAILURE);
   	}
   	if(getcwd(cwd,sizeof(cwd))!=NULL)
   	{
   		strcpy(orgdir,cwd);
   	}
	do{
		if(getcwd(cwd,sizeof(cwd))!=NULL)
		{
//			gethostname(host,500);
			tildadirec(cwd,orgdir,0);
//			printf("<%s@%s:%s>",buffer.nodename,host,cwd);
			line=readline();
			
			tr=parseline(line,";");
			int x=0;
			while(tr[x]!=NULL)
			{
			ar=parseline(tr[x]," \"\n\t");
			// while(ar[i]!=NULL)
			// {
			// 	printf("%s\n",ar[i]);
			// 	i++;
			// }
			status=execute(ar);
			free(ar);
			x++;
//			printf("back to main");
		}	free(line);
			
		
		}
	}while(status);
	
	return EXIT_SUCCESS;
}
