#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


struct stat buffer;
int main(int argc, char const *argv[])
{
	int infile;
	int outfile;  
	int k = 1000000,p=0;
	char iarr[1000000];
	char oarr[1000000];

	infile = open(argv[1],O_RDONLY);
	int countt = lseek(infile,(off_t)0,SEEK_END); 
	int status = stat("./Assignment", &buffer);
	if(status == -1) 		
	mkdir("./Assignment",0700);
	creat("./Assignment/output.txt",S_IRUSR|S_IWUSR);   
	outfile = open("./Assignment/output.txt",O_WRONLY);	  
	
	int num = countt/k, curr = 0;
	int left = countt-k*num;
	

	while(countt >0)
	{
		if(num<=curr)
        {
        	lseek(infile,(off_t)0,SEEK_SET);
        	k=left;
        	read(infile,iarr,k);

        }
		else
        {
        	lseek(infile,(off_t)countt-k,SEEK_SET);
        	curr+=1;
        	read(infile,iarr,k); 
       		
       	}   
		for(p=0;p<k;p++)
		{	
	    	if(iarr[p]>=97 && iarr[p]<=122)
	        iarr[p]=iarr[p]-32;

	    	else if(iarr[p]>=65 && iarr[p]<=90)
	        iarr[p]+=32;
	    oarr[k-1-p] = iarr[p];    	
    	}	
                      
        write(outfile,oarr,k);
        countt=countt-k;		
	}
	chmod("./Assignment",0700);
	close(infile);
	close(outfile);
	return 0;
}
