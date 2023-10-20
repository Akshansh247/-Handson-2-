/*
============================================================================
Name :24.c
Author : Akshansh Jain
Description : a program to create a message queue and print the key and message queue id.

Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

int main() {
    key_t key;
    int msgid;

    
    if ((key = ftok(".", 'b')) == -1) {
        perror("ftok");
        return -1;
    }

   
    msgid = msgget(key, IPC_CREAT | 0744);
if(msgid ==-1){
        perror("msgget");
        return -1;
    }

    
    printf("Key: 0x%0x \n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

