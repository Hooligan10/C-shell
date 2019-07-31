#include "LS.h"

int LS(char** ar)
{
	char cwd[1024];
 	DIR *dir;
 	struct dirent *dent;
 	char buffer[1024];
 	char buf[1024];
	if(getcwd(cwd,sizeof(cwd))!=NULL)
	{
		struct stat mystat;
		strcpy(buffer,cwd);
		dir=opendir(buffer);
		if(dir!=NULL)
		{
			while((dent=readdir(dir))!=NULL)
			{			
				if(!strcmp(dent->d_name,".")||!strcmp(dent->d_name,".."))
				{

				}
				if((dent->d_name[0]) =='.')
				{

				}
				else
				{
					stat(dent->d_name, &mystat);
 				//	sprintf(buf,"%s %ld\n",dent->d_name,mystat.st_size);
//					printf("%ld\t%s\n",mystat.st_size,dent->d_name);
        				printf("%s\n", dent->d_name);
				} 				
			}
		}
		closedir(dir);	
	}
}