/*
============================================================================
Name :32a_.c
Author : Akshansh Jain
Description :rewrite the ticket number creation program using semaphore
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

struct Ticket {
    int ticketNumber;
};

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


    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    key_t key ;
    int semid;
    key = ftok(".",'b');
    semid = semget(key,1,0644);
    struct Ticket ticket;
    semOp(semid ,0,-1);
    if (read(fd, &ticket, sizeof(struct Ticket)) == -1) {
        perror("Error reading ticket");
        return 1;
    }

    ticket.ticketNumber++;
    
    lseek(fd, 0, SEEK_SET);
    if (write(fd, &ticket, sizeof(struct Ticket)) == -1) {
        perror("Error writing to file");
        return 1;
    
    }
    
    getchar();

    printf("New Ticket number: %d\n", ticket.ticketNumber);
    semOp(semid,0,1);

    return 0;
}

