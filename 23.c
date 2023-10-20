/*
============================================================================
Name :23.c
Author : Akshansh Jain
Description : program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

Date: 10th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main() {
    // Get the maximum number of files that can be opened
    struct rlimit rlim;
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Maximum number of files that can be opened: %lld\n", (long long)rlim.rlim_cur);
    } else {
        perror("Error getting RLIMIT_NOFILE");
        return EXIT_FAILURE;
    }

    // Create a pipe to determine the size of a pipe (circular buffer)
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Error creating pipe");
        return EXIT_FAILURE;
    }

    // Use fcntl to get the size of the pipe
    long pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
    if (pipe_size == -1) {
        perror("Error getting pipe size");
        return EXIT_FAILURE;
    }

    printf("Size of a pipe (circular buffer): %ld bytes\n", pipe_size);

    return EXIT_SUCCESS;
}

