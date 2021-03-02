// msg from parent to child...............

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int fd[2]; // file descriptors
	//fd[0] read
	//fd[1] write
	int fd2[2]; //2nd.........	
	pipe(fd);
	pipe(fd2);
	int id;
	id = fork();
	int value;
	
	if(id == 0){
		close(fd[1]);
		read(fd[0], &value, sizeof(int));
		printf("Inside child process, changing values and sending it back\n");
		//printf("msg from parent process : %d\n", value);
		value = value - 100;
		write(fd2[1], &value, sizeof(int));
	}
	else{
		close(fd[0]);
		value = 1000;
		write(fd[1], &value, sizeof(value));
		printf("parent process sending values..............\n\n");
		read(fd2[0], &value, sizeof(int));
		printf("recieved modified value : %d\n", value);
	}
	return 0;
}


