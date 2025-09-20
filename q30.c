/*
============================================================================
Name : Q30.c
Author : Kartikey Dubey
Description : 30. Write a program to run a script at a specific time using a Daemon process.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) exit(0);  

    setsid();    // it create a new session for the orphan process (deamon process)          
    chdir("/");           //change the directory to rrot 
    umask(0); // permision reset               

    close(0); close(1); close(2); 

    int target_hour = 15;   
    int target_min  = 30;

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min) {
            system("/home/user/myscript.sh"); // Path to your script
            sleep(60); // prevent multiple runs in same minute
        }
        sleep(1);
    }
}

// output
// jeevesh@ABCD:~$ ./q301 &
// [1] 5407