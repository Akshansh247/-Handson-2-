/*
============================================================================
Name :25.c
Author : Akshansh Jain
Description : 
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv

Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;

    // Generate a key for the message queue
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Create a message queue
    if ((msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0666)) == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    // Structure to hold information about the message queue
    struct msqid_ds msq_info;

    // Get information about the message queue
    if (msgctl(msgid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    // Access permission
    printf("Access Permission: %o\n", msq_info.msg_perm.mode);

    // UID and GID
    printf("UID: %d\n", msq_info.msg_perm.uid);
    printf("GID: %d\n", msq_info.msg_perm.gid);

    // Time of last message sent and received
    printf("Time of last message sent: %s", ctime(&msq_info.msg_stime));
    printf("Time of last message received: %s", ctime(&msq_info.msg_rtime));

    // Time of last change in the message queue
    printf("Time of last change: %s", ctime(&msq_info.msg_ctime));

    // Size of the queue
    printf("Size of the queue: %lu bytes\n", msq_info.msg_qbytes);

    // Number of messages in the queue
    printf("Number of messages in the queue: %lu\n", msq_info.msg_qnum);

    // Maximum number of bytes allowed
    printf("Maximum number of bytes allowed: %lu\n", msq_info.msg_qbytes);

    // Pid of the msgsnd and msgrcv
    printf("Pid of last msgsnd: %d\n", msq_info.msg_lspid);
    printf("Pid of last msgrcv: %d\n", msq_info.msg_lrpid);

    return EXIT_SUCCESS;
}

