#include "execute.h"
//#include "main.h"
void jobs (char **ar)
 {
    int i, j = 1;
    char status[10009], status1[10009], status2[10009];
    for (i = 0; i < 32768; i++)
    {
        if (bg_processes[bg_order[i]])
        {
            char myproc[10009];
            sprintf(myproc, "%d", bg_order[i]);
            char demo[1024];
            strcpy(demo,"/proc/");
            strcat(demo,myproc);
            strcat(demo,"/stat");
            FILE *mem = fopen(demo, "r");
            fscanf(mem, "%s %s %s", status1, status2, status);
            // printf("Process Status -- %s\n", status);
            if(strcmp(status,"S")==0 || strcmp(status,"R")==0){
                strcpy(status,"Running");
            }
            else{
                strcpy(status,"Stopped");
            }
            printf("[%d] %s %s [%d]\n", j++, status, bg_processes[bg_order[i]], bg_order[i]);
        }
    }
}
int get_job_pid (int jobid) {
    int i, j = 0;
    for (i = 0; i < 32767 && j != jobid; i++)
        if (bg_processes[bg_order[i]])
            j++;
    if (i == 32767)
        return -1;
    return bg_order[i-1];
}

void kjob(char **command, int numCommands){
    pid_t pid = get_job_pid(atoi(command[1]));
    if(pid < 0){
        printf("Job %s doesn't exist\n", command[1]);
        return;
    }
    if(bg_processes[pid]){
        if(numCommands != 3){
            perror("Erorr: \n");
            return;
        }
        else{
            kill(pid, atoi(command[2]));
        }
    }
}


int execute(char** ar)
{
//	printf("In execute function\n");
//	printf("%s\n",ar[0]);
	if(strcmp(ar[0],"cd")==0)
	{
//		printf("in if of cd\n");
		ChangeDirec(ar);
		return 1;
	}
	else if(strcmp(ar[0],"echo")==0)
	{
//		printf("in if of echo\n");
		ECHO(ar);
		return 1;
	}
	else if(strcmp(ar[0],"pwd")==0)
	{
//		printf("in if of pwd\n");
		PWD(ar);
		return 1;
	}
 //	printf("exiting execute\n");

 	else if(strcmp(ar[0],"ls")==0 && ar[1]==NULL)
 	{
// 		printf("Hello");
 		LS(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"ls")==0 && strcmp(ar[1],"-l")==0 && ar[2]==NULL)
 	 {
 	 	LSl(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"ls")==0 && strcmp(ar[1],"-a")==0 && ar[2]==NULL)
 	{
 		LSa(ar);
 		return 1;
 	}
 	else if((strcmp(ar[0],"ls")==0) && (((strcmp(ar[1],"-la")==0) ||(strcmp(ar[1],"-al")==0)) || ((strcmp(ar[1],"-l")==0) && (strcmp(ar[2],"-a")==0)) || ((strcmp(ar[1],"-a")==0) && (strcmp(ar[2],"-l")==0))))
 	{
 		LSla(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"pinfo")==0)
 	{
 		pinfo(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"setenv")==0)
 	{
 		Setenv(ar);
 		return 1;
 	}
 	else if (strcmp(ar[0],"getenv")==0)
 	{
 		Getenv(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"unsetenv")==0)
 	{
 		Unsetenv(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"quit")==0)
 	{
 		return 0;
 	}
 	else if(strcmp(ar[0],"jobs")==0)
 	{
 		jobs(ar);
 		return 1;
 	}
 	else if(strcmp(ar[0],"kjob")==0)
 	{
 		int op=0;
 		while(ar[op]!=NULL)
 		{
 			op++;
 		}
 		kjob(ar,op);
 		return 1;
 	}
 	else
 	{
 		int i=0,fi=0,fw=0,fa=0,rein=0,reout=0,reapp=0,flag=0;
 		int a[100]={0},k=0;
 		while(ar[i]!=NULL)
 		{
 			if(strcmp(ar[i],"<")==0)
 			{
 			//	printf("Heloo\n");
 				rein=i;
 				fi=1;
 				flag=1;
 	//			RedirectI(ar,rein); 				 
 			}
 			else if(strcmp(ar[i],">")==0)
 			{
 				reout=i;
 				fw=1;
 				flag=1;	 			
 			}
 			else if(strcmp(ar[i],"|")==0)
 			{
 				a[k++]=i;
 				flag=2;
 			}
 			else if(strcmp(ar[i],">>")==0)
 			{
 				reapp=i;
 				fa=1;
 				flag=1;
 //				append(ar,i);
 			}
 			i++;
 		}
 		if(flag==2)
 		{
// 			printf("%d\n",k);
 			Piping(ar,a,k);
 			return 1;
 		}
 		if(flag==1)
 		{
 			Redirect(ar,fi,fw,fa,rein,reout,reapp);
 			return 1;
 		}
 		if(flag!=1 && flag!=2)
 		{
 			FGc(ar);
 			return 1;
 		}
	}
}
