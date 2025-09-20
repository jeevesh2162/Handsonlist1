/*
============================================================================
Name : Q21.c
Author : Jeevesh Rai
Description : Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    printf("Id of parent process is = %d\n", getpid());
    int a = fork();   // this will give the pid of child process to the parent 
    if (a) //parent will enter and print the pid of child
        printf("Id of child process is = %d\n", a);
    
    return 0;
}
/*
Output:
Id of parent process is = 80756
Id of child process is = 80757
*/
