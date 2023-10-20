/*
============================================================================
Name :26.c
Author : Akshansh Jain
Description : a program to send messages to the message queue. Check $ipcs -q

Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
int main() {
key_t key;
int mqid;
struct msg {
long int m_type;
char message[80];
} myq;
key = ftok(".", 'a');
mqid = msgget(key, 0);
write(1,"Enter message type: ",18);
scanf("%ld", &myq.m_type);
write(1,"Enter message text:",19);
read(0,myq.message,sizeof(myq.message));
int size = strlen(myq.message);
msgsnd(mqid, &myq, size + 1, 0);
return 0;
}
