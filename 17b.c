#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(!pid){
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls","ls","-l",(char*)NULL);
	}
	else{
		close(fd[1]);
		dup2(fd[0],0);
		execlp("wc","wc",(char*)NULL);
	}}
