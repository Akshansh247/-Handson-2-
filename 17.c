/*
============================================================================
Name :17.c
Author : Akshansh Jain
Description : Write a program to execute ls -l | wc.
a. use dup

Date: 8th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
int fd[2];
 pipe(fd);
 int pid = fork();
if (!pid) {
close(1); 
close(fd[0]);
dup(fd[1]); 
execlp("ls", "ls", "-l", (char*) NULL);


}
else {
close(0); 
close(fd[1]);
dup(fd[0]); 
execlp("wc", "wc", (char*) NULL);

}
}
