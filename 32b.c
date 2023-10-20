/*
============================================================================
Name :32b.c
Author : Akshansh Jain
Description :protect pseudo resources 
Date: 10th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


void semOp(int semid, int semnum, int op) {
    struct sembuf semaphore;
    semaphore.sem_num = semnum;
    semaphore.sem_op = op;
    semaphore.sem_flg = 0;
    if (semop(semid, &semaphore, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}
int main() {


   
    key_t key ;
    int semid;
    key = ftok(".",'b');
    semid = semget(key,1,0644);
  
    semOp(semid ,0,-1);
    getchar();
    write(1,"into the critical section",25);

   
    
  
   
    
    getchar();

   
    semOp(semid,0,1);

    return 0;
}

