/*
============================================================================
Name :21_.c
Author : Akshansh Jain
Description : two programs so that both can communicate by FIFO -Use two way communication.
Date: 10 Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	
	
	char buff[100];
	int fd1 = open("fifo",O_RDONLY);
	read(fd1,buff,sizeof(buff));

	write(1,buff,sizeof(buff));
        write(1,"lets write from our side -> ",28);
	int fd2 = open("fifo2",O_WRONLY);
	read(0,buff,sizeof(buff));
	write(fd2,buff,sizeof(buff));
	return 0;
}
