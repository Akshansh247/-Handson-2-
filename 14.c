/*
============================================================================
Name :14.c
Author : Akshansh Jain
Description :  a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
int i, j, fd[2];
char buf[80];
i = pipe(fd);
if(i<0){
	write(1,"error creating pipe",7);
	return -1;
}

char input[100];
read(0,input,sizeof(input));

write(fd[1], input, sizeof(input));

read(fd[0], buf, sizeof(buf));
write(1,buf,sizeof(buf));
return 0;
}
