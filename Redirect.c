#include "Redirect.h"
#include "FGc.h"
int Redirect(char **ar,int fi,int fw,int fa,int rein,int reout,int reapp)
{
	char **temp=malloc(sizeof(char)*128);
	if(fi==1 && fw==0 && fa==0)
	{
		int in,j;
		in=open(ar[rein+1],O_TRUNC|O_RDONLY);
//		if(in!=1)
//		{
//			in=creat(ar[rein+1],0766);
//		}
		
//		char **temp=malloc(sizeof(char)*128);
		for(j=0;j<rein;j++)
		{
			temp[j]=ar[j];
		}
		temp[rein]=NULL;
		if(dup2(in,0)!=0)
		{
			perror("dup2 in < failed");
//			exit(EXIT_FAILURE);
		}
//		FGc(temp);
//		pid_t p=fork();
		execvp(temp[0],temp);
	}
	else if(fi==0 && fw==1 && fa==0)
	{
		int out,j;
		out=open(ar[reout+1],O_TRUNC|O_WRONLY);
		if(out!=1)
		{
			out=creat(ar[reout+1],0766);
		}
		if(dup2(out,1)!=1)
		{
			perror("dup2 in > failed");
//			exit(EXIT_FAILURE);
		}
//		char **temp=malloc(sizeof(char)*128);
		for(j=0;j<reout;j++)
		{
			temp[j]=ar[j];
		}
		temp[reout]=NULL;
//		FGc(temp);
//		pid_t p=fork();
		execvp(temp[0],temp);
		//	execvp(temp[0],temp);
	}
	else if(fi==0 && fw==0 && fa==1)
	{
		int app,j;
		app=open(ar[reapp+1],O_TRUNC|O_APPEND);
		if(app!=1)
		{
			app=creat(ar[reapp+1],0766);
		}
//		char **temp=malloc(sizeof(char)*128);
		for(j=0;j<reapp;j++)
		{
			temp[j]=ar[j];
		}
		temp[reapp]=NULL;
		if(dup2(app,1)!=1)
		{
			perror("dup2 in >> failed");
		}
//		FGc(temp);
//		pid_t p=fork();
		execvp(temp[0],temp);
		
//		execvp(temp[0],temp);
	}
	else if(fi==1 && fw==0 && fa==1)
	{
		int in,app,j;
		in=open(ar[rein+1],O_TRUNC|O_RDONLY);
//		if(in!=1)
//		{
//			in=creat(ar[rein+1],0777);
//		}
		
//		char **temp=malloc(sizeof(char)*128);
		for(j=0;j<rein;j++)
		{
			temp[j]=ar[j];
		}
		temp[rein]=NULL;
		if(dup2(in,0)!=0)
		{
			perror("dup2 in < failed");
		}
		
		app=open(ar[reapp+1],O_TRUNC|O_APPEND);
		if(app!=1)
		{
			app=creat(ar[reapp+1],0766);
		}
		if(dup2(app,1)!=1)
		{
			perror("dup2 in >> failed");
		}
//		FGc(temp);
//		pid_t p=fork();
		execvp(temp[0],temp);
		
	}
	else if(fi==1 && fw==1 && fa==0)
	{
		int in,out,j;
		in=open(ar[rein+1],O_TRUNC|O_RDONLY);
//		if(in!=1)
//		{
//			in=creat(ar[rein+1],0777);
//		}
		
//		char **temp=malloc(sizeof(char)*128);
		for(j=0;j<rein;j++)
		{
			temp[j]=ar[j];
		}
		temp[rein]=NULL;
		if(dup2(in,0)!=0)
		{
			perror("dup2 in < failed");
		}
		out=open(ar[reout+1],O_TRUNC|O_WRONLY);
		if(out!=1)
		{
			out=creat(ar[reout+1],0766);
		}
		if(dup2(out,1)!=1)
		{
			perror("dup2 in > failed");
		}
//		FGc(temp);
		execvp(temp[0],temp);
	}
	
}
