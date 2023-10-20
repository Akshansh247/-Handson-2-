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
char *data;
key = ftok(".", 'a');

shmid = shmget(key, 1024, 0);
data = shmat(shmid, 0, 0);
write(1,data,100);
return 0;
}
