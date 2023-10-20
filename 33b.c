/*
============================================================================
Name :33.c
Author : Akshansh Jain
Description :a program to communicate between two machines using socket.
Date: 10th Oct, 2023.
============================================================================
*/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main() {
struct sockaddr_in serv;
int sd;
char buf[80];
sd = socket(AF_UNIX, SOCK_STREAM, 0);
serv.sin_family = AF_UNIX;

serv.sin_addr.s_addr = INADDR_ANY;serv.sin_port = htons(3560); 

connect(sd, (void*) (&serv), sizeof(serv));
getchar();
write(sd, "Hello Server\n", 14);
read(sd, buf, sizeof(buf));
printf("Message from server: %s\n", buf);
}
