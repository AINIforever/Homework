#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int 
tcp(const char* source, const char* target);

int 
main(int argc, const char *argv[])
{	
	//ensure the parameter is not null 
	if (argv[2]==0)
		exit(EXIT_FAILURE);
	tcp(argv[1], argv[2]);
    exit(EXIT_SUCCESS);
	
}

int 
tcp(const char* source, const char* target)
{
	ssize_t n;
	int fd[2];
	char buf[BUFFSIZE];
	
    //open source file, get descripter
	if ((fd[0]=open( source, O_RDONLY )) < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}
	//make sure the argv[2] is a directory or a file, and excute in different occations.
	struct stat st;
 	stat(target,&st);
 	if (S_ISDIR(st.st_mode)){
		char path[100]; 
		sprintf(path,"%s%s",target,source);
		if ((fd[1] = open(target, O_RDWR | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IXUSR)) < 0)
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
			
	while( (n= read( fd[0], buf, BUFFSIZE)) > 0){
		if ( write( fd[1], buf, n) != n){
			perror("open error");
			exit(EXIT_FAILURE);
		}
			
	}

	close(fd[0]);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}
