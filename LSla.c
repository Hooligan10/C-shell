#include "LSla.h"

int LSla(char** ar)
{
	char cwd[1024];
 	DIR *dir;
 	struct dirent *dent;
 	char buffer[1024];
 	char buf[1024];
	if(getcwd(cwd,sizeof(cwd))!=NULL)
	{
 		long long int filec=0;
 		struct stat mystat;
 		strcpy(buffer,cwd);
 		dir=opendir(buffer);
 		if(dir!=NULL)
 		{
 			while((dent=readdir(dir))!=NULL)
 			{
 				filec++;	
 			}
 		}
 		closedir(dir);
 		printf("%lld\n",filec);
 		dir=opendir(buffer);
 		struct stat info;
 		if(dir!=NULL)
 		{
 			while((dent=readdir(dir))!=NULL)
 			{
 				stat(dent->d_name, &mystat);
 			//	sprintf(buf,"%s %ld\n",dent->d_name,mystat.st_size);
 				printf( (S_ISDIR(mystat.st_mode)) ? "d" : "-");
    			printf( (mystat.st_mode & S_IRUSR) ? "r" : "-");
    			printf( (mystat.st_mode & S_IWUSR) ? "w" : "-");
				printf( (mystat.st_mode & S_IXUSR) ? "x" : "-");
				printf( (mystat.st_mode & S_IRGRP) ? "r" : "-");
				printf( (mystat.st_mode & S_IWGRP) ? "w" : "-");
				printf( (mystat.st_mode & S_IXGRP) ? "x" : "-");
				printf( (mystat.st_mode & S_IROTH) ? "r" : "-");
				printf( (mystat.st_mode & S_IWOTH) ? "w" : "-");
				printf( (mystat.st_mode & S_IXOTH) ? "x" : "-");
				printf("\t%lu",mystat.st_nlink);
				struct passwd *pw = getpwuid(mystat.st_uid);
				struct group  *gr = getgrgid(mystat.st_gid);
				printf("\t%s\t%s",pw->pw_name,gr->gr_name);
				printf("\t%ld",mystat.st_size);
				time_t t = mystat.st_mtime;
	//			stime_t t = mystat.st_mtime;
				struct tm lt;
				//	struct tm *tm;
				//	char buf[200];
/* convert time_t to broken-down time representation */
				localtime_r(&t,&lt);
				char time_buffer[1024];
				strftime(time_buffer, sizeof(time_buffer),"%c",&lt);
				printf("\t%s", time_buffer);
				printf("\t%s\n",dent->d_name);
			}						 				
 				
 		}	
 		closedir(dir);	
 	}
}