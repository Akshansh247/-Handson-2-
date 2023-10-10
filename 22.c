#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
int main(){
	fd_set rfds;
	struct timeval tv;
	tv.tv_sec = 10;
	tv.tv_usec = 0;

      int fd = open("fifo",O_NONBLOCK | O_RDONLY);
        FD_ZERO(&rfds);
	FD_SET(fd,&rfds);
	int f = select(fd+1,&rfds,NULL,NULL,&tv);
	if(!f){
		write(1,"huh , nobody is writing ",24);
	}

	else{
        char buff[100];
	read(fd ,buff,sizeof(buff));
	write(1,buff,sizeof(buff));
	return 0;
}
}
