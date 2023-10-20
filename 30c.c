/*
============================================================================
Name :30b.c
Author : Akshansh Jain
Description :attach with O_RDONLY and check whether you are able to overwrite.
Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
int key, shmid;
char*data;
key = ftok(".", 'b');

shmid = shmget(key, 1024, 0744);
data = shmat(shmid, 0, SHM_RDONLY);
write(1,"Enter the text : ",17);
int f = read(0,data,100);
if(f<-1){
	write(1,"nope noway ",10);
}
return 0;
}
