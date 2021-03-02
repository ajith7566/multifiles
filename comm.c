#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd[2];
	// fd[0] read
	// fd[1] write

	if(pipe(fd)<0){
		printf("Error\n");
		return -1;
	}
	int id = fork();
	/*
	if(id == 0){
            close(fd[0]);
	    int val = 5000;
	    write(fd[1], &val, sizeof(int));
	    close(fd[1]);
	}
	else{
	     int values;
	     read(fd[0], &values, sizeof(values));
	     printf("message from child : %d\n", values);
	}
	*/
	if(id == 0){
		int values;
		read(fd[0], &values, sizeof(values));
		printf("message from parent : %d\n", values);
	}
	else{
		close(fd[0]);
		int val = 5000;
		write(fd[1], &val, sizeof(int));
		close(fd[1]);
	}
	return 0;
}
