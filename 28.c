/*
============================================================================
Name :28.c
Author : Akshansh Jain
Description :a program to change the exiting message queue permission. (use msqid_ds st
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

    // Get the current message queue status
    struct msqid_ds msq_info;
    if (msgctl(msgid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    // Display the current permissions
    printf("Current Message Queue Permissions: %o\n", msq_info.msg_perm.mode);

    // Change the permission (for example, to read and write for user and group)
    msq_info.msg_perm.mode = 0660;

    // Update the message queue status with the new permission
    if (msgctl(msgid, IPC_SET, &msq_info) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    // Display the updated permissions
    printf("Updated Message Queue Permissions: %o\n", msq_info.msg_perm.mode);

    return EXIT_SUCCESS;
}

