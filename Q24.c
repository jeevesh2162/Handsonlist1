
/*
============================================================================
Name : Q24.c
Author : Jeevesh Rai
Description : Write a program to create an orphan process.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
  
int main() 
{ 
    int pid = fork(); 
  
    if (pid > 0) {
        printf("inside parent pid= %d\n", getpid());
        printf("child pid= %d\n", pid);
    } 
    else if (pid == 0) 
    { 
        printf("inside child pid= %d\n", getpid());
        sleep(10);
        // exit(EXIT_SUCCESS);
        printf("inside child parent pid= %d\n", getppid());

    }
    return 0; 
} 
/*
Output:
inside child pid= 81614
parent id= 81613
*/
