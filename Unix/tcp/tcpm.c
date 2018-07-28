#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdlib.h>


int 
tcpm(const char* source, const char* target);

int 
main(int argc, const char *argv[])
{	
	//ensure the parameter geted is leagal
	if (argv[2]==0)
		exit(EXIT_FAILURE);
	tcpm(argv[1], argv[2]);
    exit(EXIT_SUCCESS);
	
}

int 
tcpm(const char* source, const char* target)
{
	int fd[2]; 
    void *src;
    void *dst;
    ssize_t num;
    struct stat st;
	//open source file, get descripter
    if ((fd[0]=open( source, O_RDONLY )) < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}
	num = lseek(fd[0], 0, SEEK_END); 
	//make sure the argv[2] is a directory or a file, and excute in different occations.
	stat(target,&st);
	if(S_ISDIR(st.st_mode)){
		char path[100];
		sprintf(path,"%s%s",target,source);
		if ((fd[1] = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IXUSR)) < 0)
    	{   
        	close(fd[0]);
        	exit(EXIT_FAILURE);
    	}
	}
	else{
		if ((fd[1] = open(target, O_RDWR | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IXUSR)) < 0)
    	{   
        	close(fd[0]);
        	exit(EXIT_FAILURE);
    	}
	}
    
    
    ftruncate(fd[1], num);


    if((src = mmap(NULL, num, PROT_READ,MAP_PRIVATE,fd[0],0)) < 0)
        exit(EXIT_FAILURE);
    if((dst = mmap(NULL, num, PROT_WRITE,MAP_SHARED,fd[1],0)) < 0)
        exit(EXIT_FAILURE);

    
    
	munmap(src,num); 
    munmap(dst,num);
    memcpy(dst,src,num);
   

    close(fd[0]);
    close(fd[1]);
    exit(EXIT_SUCCESS);
}
