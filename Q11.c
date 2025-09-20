/*
============================================================================
Name : Q11.c
Author : Jeevesh Rai
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    int fd1 = open("Q11sample.txt", O_WRONLY);
    
    // Using dup
    int fd2 = dup(fd1);
    char f1[] = "dup()\n";
    write(fd2, &f1, sizeof(f1));

    // Using dup2
    int fd3 = dup2(fd1, 100);
    char f2[] = "dup2()\n";
    write(fd3, &f2, sizeof(f2));

    // Using fcntl
    int fd4 = fcntl(fd1, F_DUPFD, 0);
    char f3[] = "fcntl()\n";
    write(fd4, &f3, sizeof(f3));

    return 0;
}
