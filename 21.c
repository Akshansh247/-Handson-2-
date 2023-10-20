/*
============================================================================
Name :21.c
Author : Akshansh Jain
Description : two programs so that both can communicate by FIFO -Use two way communication.

Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	
	write(1,"what do you want to write write here->  ",39);
	char buff[100];
	read(0,buff,sizeof(buff));
	int fd1 = open("fifo",O_WRONLY);
	write(fd1,buff,sizeof(buff));
	write(1,"\n let's see what other side is writing \n",41);
	int fd2 = open("fifo2",O_RDONLY);
        char buff2[100];
	read(fd2,buff2,sizeof(buff2));
	write(1,buff2,sizeof(buff2));

	return 0;
}
