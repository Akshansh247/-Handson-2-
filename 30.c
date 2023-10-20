/*
============================================================================
Name :30.c
Author : Akshansh Jain
Description :write some data to the shared memory
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
key = ftok(".", 'a');

shmid = shmget(key, 1024, IPC_CREAT|0744);
data = shmat(shmid, 0, 0);
write(1,"Enter the text : ",17);
read(0,data,100);
shmdt(data);
return 0;
}
