#include "Piping.h"

int child(int in,int out,char **temp)
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		if(in!=0)
		{
			if(dup2(in,0)!=0)
			{
				perror("dup2 in child failed");
			}
			close(in);
		}
		if(out!=1)
		{
			if(dup2(out,1)!=1)
			{
				perror("dup2 in child failed");
			}
			close(out);
		}
		return execvp(temp[0],temp);
	}
	return pid;
}

int Piping(char **ar,int a[],int k)
{
	int i,len,fd[2];
	len=k+1;
	int in=0,var=0,t=0,j;
	char **temp=malloc(sizeof(char)*128);
	for(i=0;i<k;i++)
	{
		pipe(fd);
		t=0;
		for(j=var;j<a[i];++j)
		{
			temp[t++]=ar[j];
		}
		var=a[i]+1;
		temp[t]=NULL;
//		printf("hello1\n");
		child(in,fd[1],temp);
//		printf("hello2\n");
		close(fd[1]);
		in=fd[0];
	}
	if(in!=0)
	{
//		printf("hello3\n");
		dup2(in,0);
	}
	int p;
	// printf("K is %d\n",k);
	// for(p=0;p<k;p++)
	// {
	// 	printf("dande:\n");
	// 	printf("%d\n",a[p]);
	//
	i=a[k-1]+1;
	// printf("\n");
	// printf("wo wala\n");
	// printf("%s\n",ar[i]);
	// printf("hello4\n");
	// for(p=0;p<k;p++)
	// {	printf("temp:\n");
	// 	printf("%s\n",temp[p]);
	// }
	while(ar[i]!=NULL)
	{
		temp[i-(a[k-1]+1)]=ar[i];
		i++;
	}
	temp[i-(a[k-1]+1)]=NULL;
	
	// for(p=0;p<i-(a[k-1]+1);p++)
	// {
	// 	printf("temp phir se:\n");
	// 	printf("%s\n",temp[p]);
	// }

	int manik = execvp(temp[0],temp);
//	printf("%d\n",manik);
	return manik;
}

