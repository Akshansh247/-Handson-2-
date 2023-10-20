/*
============================================================================
Name :33.c
Author : Akshansh Jain
Description :a program to communicate between two machines using socket.
Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{struct sockaddr_in serv, cli;
int sd, nsd;
char buf[80];
// sd = Socket Descriptor
sd = socket(AF_UNIX, SOCK_STREAM, 0);
serv.sin_family = AF_UNIX;
// Specify destination address of socket
// INADDR_ANY = Automatically assign IP address (of current machine)
serv.sin_addr.s_addr = INADDR_ANY;
// Meaning of htons() will be explained later
serv.sin_port = htons(3548);
// sd has become the server now
bind(sd, (void*) (&serv), sizeof(serv));
listen(sd, 5); // 5 = size of wait queue for connections
int sz = sizeof(cli);

nsd = accept(sd, (void*) (&cli), &sz);
// Read data sent by cli (nsd) and store it in buf
read(nsd, buf, sizeof(buf));
printf("Message from client: %s\n", buf);
write(nsd, "ACK from Server\n", 17);

}
