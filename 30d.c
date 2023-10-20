/*
============================================================================
Name :30b.c
Author : Akshansh Jain
Description :remove the shared memory
Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
int main() {
    key_t key;
    int shmid;
    

    if ((key = ftok(".", 'b')) == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

  
    if ((shmid = shmget(key, 1024, 0744)) == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

   

    
   

    
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return EXIT_FAILURE;
    }
write(1,"deleted successfully",20);
    return EXIT_SUCCESS;
}

