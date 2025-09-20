/*
============================================================================
Name : Q14.c
Author : Jeevesh Rai
Description : Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. Program should be able to identify any type of a file.
Date: 28th Aug, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <fcntl.h>

int main(int argv, char *argc[])
{
    struct stat status;
    int i = lstat(argc[1], &status);
    if (i == -1) {
        perror("lstat error");
        exit(EXIT_FAILURE);
    }

    printf("The file type is:                ");

    switch (status.st_mode & S_IFMT)
    {
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case S_IFLNK:
            printf("symlink\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown?\n");
            break;
    }

    return 0;
}

/*
Output: 
jeevesh@ABCD:~/ss_work$ gcc Q14.c
jeevesh@ABCD:~/ss_work$ ./a.out temp.txt
The file type is:                regular file
*/
