#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);
       int pid = fork();
	if(!pid){
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		dup2(fd1[1],1);
		execlp("ls","ls","-l",(char*)NULL);}
	else{
	pid = fork();
	if(!pid){
	close(fd1[1]);
	close(fd2[0]);
	dup2(fd1[0],0);
	dup2(fd2[1],1);
	execlp("grep","grep","^d",(char*)NULL);}
	else{
	close(fd1[0]);
	close(fd1[1]);
        close(fd2[1]);
        dup2(fd2[0],0);
	execlp("wc","wc",(char*)NULL);}}}
