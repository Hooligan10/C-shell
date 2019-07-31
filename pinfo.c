#include "pinfo.h"

int pinfo(char** ar)
{
 		char pathloc[1024],statloc[1024],status,name[1024];
 		int c,pid,memorysize;
 		if(ar[1]==NULL)
 		{
 			strcpy(pathloc,"/proc/self");
 		}
 		else
 		{
 			char loc[150]="/proc/";
 			strcat(loc,ar[1]);
 			strcpy(pathloc,loc);
 		}
 		strcpy(statloc,pathloc);
 		strcat(statloc,"/stat");
 		
 		errno = 0;
 		FILE * info = fopen(statloc, "r");
    	if(errno)
    	{
        	fprintf(stderr, "Error reading %s: %s\n", statloc, strerror(errno));
			return 1;
		}		
    	
    	fscanf(info,"%d %s %c",&pid,name,&status);
    	fprintf(stdout,"pid: %d\n",pid);
    	fprintf(stdout,"Process Status: %c\n",status);
    	fclose(info);
    	errno = 0;
    	strcpy(statloc,pathloc);
    	strcat(statloc, "/statm");
	    FILE * memoinfo = fopen(statloc,"r");
	    if(errno)
	    {
			fprintf(stderr, "Error reading %s: %s\n", statloc, strerror(errno));
	        return 1;
	    }
	    fscanf(memoinfo, "%d", &memorysize);
	    fprintf(stdout,"Memory: %d\n",memorysize);
	    fclose(memoinfo);
	    char executepath[1000];
	    strcpy(statloc,pathloc);
	    strcat(statloc,"/exe");
	//    errno = 0;
	    readlink(statloc,executepath,sizeof(executepath));
	    errno=0;
	    if(errno)
	    {
	        fprintf(stderr,"Error reading symbolic link %s: %s\n", statloc,strerror(errno));
	        return 1;
	    }
	    tildadirec(executepath,orgdir,1);
//	    printf("%s\n",executepath);
	    return 1;
}
