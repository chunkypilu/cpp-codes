    #include <stdio.h>
	#include <sys/types.h> 
	#include <sys/stat.h> 
	#include <fcntl.h> 
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	
	void main(int args, char *argv[])
	{
	
	char source[500];
	char destination[500];
	int size;
	struct stat st;
	
	
	
        printf("Enter location, where to create, Directly enter file name if u wants to ceate in home only:-\n");
        scanf("%s",source);
	
	    if(open(source,O_RDONLY)>=0)
          {
            printf("File exists\n");
            exit(1);
          }

	int fd=open(source,O_WRONLY|O_APPEND|O_CREAT, S_IRWXU);//opening file in which to write
	printf("Enter size of the file in mb\n");
	scanf("%d",&size);
    size=size*1000000;
	char* buf = malloc(size);
	memset(buf, 0, size);
    write(fd,buf,size);
    close(fd);
    
    }
