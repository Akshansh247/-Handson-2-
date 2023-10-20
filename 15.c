/*
============================================================================
Name :15.c
Author : Akshansh Jain
Description : a simple program to send some data from parent to the child process.
Date: 8th Oct 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
char buff[80];
int fd[2];
pipe(fd);
if (fork()) {
close(fd[0]);
write(1,"write here ----->  ",17);
read(0,buff,sizeof(buff)); 
write(fd[1], buff, sizeof(buff));
return 0;
}
else {
close(fd[1]); 
read(fd[0], buff, sizeof(buff));
write(1,buff,sizeof(buff));
}

return 0;
}

