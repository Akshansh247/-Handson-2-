#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
      int fd = open("fifo",O_RDONLY);
	char buff[100];
	read(fd,buff,sizeof(buff));
	write(1,buff,sizeof(buff));

	return 0;
}

