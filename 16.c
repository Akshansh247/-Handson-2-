#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
	int fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);
	int pid = fork();
	if(!pid){close(fd1[1]);
                close(fd2[0]);
		char buff[100];
                read(fd1[0],buff,sizeof(buff));
		write(1,buff,sizeof(buff));
		write(1,"wanna send something? \n",24);
		char buf2[100];
		read(0,buf2,sizeof(buf2));
		write(fd2[1],buf2,sizeof(buf2));

		return 0;
		}
       else{
            close(fd1[0]);
	    close(fd2[1]);
            char buffer[100];
	    write(1,"write something \n",18);
	    read(0,buffer,sizeof(buffer));
	    write(fd1[1],buffer,sizeof(buffer));
	    char buffer2[100];
	    read(fd2[0],buffer2,sizeof(buffer2));
            write(1,buffer2,sizeof(buffer2));
	    }
	    return 0;}
