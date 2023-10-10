#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(!pid){close(1);
		close(fd[0]);
		fcntl(fd[1],F_DUPFD,1);
		execlp("ls","ls","-l",(char*)NULL);
	}
	else{   close(0);
		close(fd[1]);
		fcntl(fd[0],F_DUPFD,0);
		execlp("wc","wc",(char*)NULL);
	}}
