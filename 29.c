/*
============================================================================
Name :29.c
Author : Akshansh Jain
Description :a program to remove the message queue.
Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate a key for the message queue (same key as used for creation)
    if ((key = ftok(".", 'b')) == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Get the message queue ID
    if ((msgid = msgget(key, 0)) == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    printf("Message queue removed successfully.\n");

    return EXIT_SUCCESS;
}

