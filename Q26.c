
/*
============================================================================
Name : Q26.c
Author : Kartikey Dubey
Description : Write a program to execute an executable program.
             a. use some executable program
             b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main()
{  
    char* arg[] = {"cat", "file1.txt", NULL};
    execv("/bin/cat", arg);
    return 0;
}
/*
Output:
File1
Kartikey Dubey
This is my file
*/
