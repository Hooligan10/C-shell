#include "tildadirec.h"

char tildadirec(char* cwd,char* orgdir,int fl)
{
	char host[1024];
	struct utsname buffer;
	errno = 0;
   	if (uname(&buffer) != 0)
   	{
      perror("uname");
      exit(EXIT_FAILURE);
   	}
	gethostname(host,500);
	int i=0,flag=0,j,p=0;
	int lencwd=strlen(cwd);
	int lenorg=strlen(orgdir);
	if(fl==0)
	{
		if(strcmp(cwd,orgdir)==0)
		{
			printf("<%s@%s:~/>",buffer.nodename,host);
		}
		else
		{
			for(i=0;i<lenorg;i++)
			{
				if(cwd[i]!=orgdir[i])
				{
					flag=1;
					p=i;
					break;
				}
			}
			if(flag==0)
			{
				printf("<%s@%s:~",buffer.nodename,host);
				for(j=i;j<lencwd;j++)
				{
					printf("%c",cwd[j]);
				}
				printf(">");
			}
			else
			{
				printf("<%s@%s:%s>",buffer.nodename,host,cwd);		
			}
		}
	}
	else
	{
		flag=0;
		for(i=0;i<lenorg;i++)
		{
			if(cwd[i]!=orgdir[i])
			{
				flag=1;
				p=i;
				break;
			}
		}
		if(flag==0)
		{
			printf("~");
			for(j=i;j<lencwd;j++)
			{
				printf("%c",cwd[j]);
			}
		}
		else
		{
			printf("%s\n",cwd);		
		}
	}
	
}		