	#include <stdio.h>
	#include <sys/types.h> 
	#include <sys/stat.h> 
	#include <fcntl.h> 
	#include <stdlib.h>
	#include <unistd.h>
	#include <time.h>
	

	void main(int args, char *argv[])
	{
        
        struct stat st;
        char source[500];
        char destination[500];
        double time_diff;
        clock_t start_time, end_time;
        printf("Enter source location:-\n");
        scanf("%s",source);
        printf("Enter destination location:-\n");
        scanf("%s",destination);
        
        
        
    start_time=clock();
	int fd=open(source,O_RDONLY);
	
	if(fd<0)
	{
	printf("Err in opening file\n");
	exit(1);
	}
	
	
	stat(source, &st);  //Extracting size
	printf("sent File size: %ld bytes\n", st.st_size);
	
	
	
	char* buf = malloc(st.st_size);  //creating buffer of file size
	read(fd,buf,st.st_size);
        
        
        if(open(destination,O_RDONLY)>=0)
        {
        printf("File exists\n");
        exit(1);
        }
        printf("recieved File size: %ld bytes\n", st.st_size);
	    int fd1=open(destination,O_WRONLY|O_APPEND|O_CREAT, S_IRWXU);//opening file in which to write
        write(fd1,buf,st.st_size); //writing to the new file
        close(fd);
        close(fd1);
        //deleting file at destination
        remove(source);
        end_time=clock();
        time_diff = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("time taken=%f sec\n",time_diff);

        
	}

