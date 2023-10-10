#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
	
        write(1,"what do you want to write ? \n" ,30);
        char buff[100];
	read(0,buff,sizeof(buff));
	int fd = open("fifo",O_WRONLY);
        write(fd,buff,sizeof(buff));
	return 0;
	}
 
