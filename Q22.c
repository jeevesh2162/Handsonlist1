/*
============================================================================
Name : Q22.c
Author : Jeevesh Rai
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
             parent processes. Check output of the file.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>   // for strlen(), snprintf()
#include <stdlib.h>   // for exit()

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    const char *file_name = "22_sample.txt";
    int a = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (a == -1) {
        perror("open");
        exit(1);
    }

    printf("Writing to file: %s (PID: %d)\n", file_name, getpid());

    char arr[64];
    sprintf(arr, "written by process %d\n", getpid());

    if (write(a, arr, strlen(arr)) == -1) {
        perror("write");
    }

    close(a);
    return 0;
}
/*
Output:
jeevesh@ABCD:~$ cat 22_sample.txt
written by process 5218
written by process 5219
*/
