/*
============================================================================
Name :31.c
Author : Akshansh Jain
Description :create a binary semaphor
Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


union semun {
    int val;               
    struct semid_ds *buf;  
    unsigned short *array; 
    struct seminfo *__buf; 
};

int main() {
    key_t key;
    int semid;

    
    if ((key = ftok(".", 'b')) == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

   
    if ((semid = semget(key, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        return EXIT_FAILURE;
    }

    
    union semun sem_init;
    sem_init.val = 1;

    if (semctl(semid, 0, SETVAL, sem_init) == -1) {
        perror("semctl");
        return EXIT_FAILURE;
    }

    printf("Counting semaphore created and initialized successfully.\n");

    

    return EXIT_SUCCESS;
}

