/*
============================================================================
Name :34.c
Author : Akshansh Jain
Description :a program to communicate betn client andm server , in 33rd program there is a code that can be used to perform .
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
/
serv.sin_addr.s_addr = INADDR_ANY;
/
serv.sin_port = htons(3560);
/
bind(sd, (void*) (&serv), sizeof(serv));
listen(sd, 5); // 5 = size of wait queue for connections
int sz = sizeof(cli);
while(1){
nsd = accept(sd, (void*) (&cli), &sz);
if(!fork()){
	close(sd);
read(nsd, buf, sizeof(buf));
printf("Message from client: %s\n", buf);
write(nsd, "ACK from Server\n", 17);
exit(0);
}
else{
	close(nsd);

}}
}
