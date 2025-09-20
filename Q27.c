
/*
============================================================================
Name : Q27.c
Author : Kartikey Dubey
Description : Write a program to execute ls -Rl by the following system calls
             a. execl
             b. execlp
             c. execle
             d. execv
             e. execvp
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *env[])
{
    char *path = "/bin/ls";

    execl(path, path, "-Rl", NULL); // a

    char *path2 = "ls";
    execlp(path2, path2, "-Rl", NULL); // b

    execle(path, path, "-Rl", "27c_example/", NULL, env); // c

    char *argv[] = {path, "-Rl", NULL};
    execv(path, argv); // d

    char *buf[] = {path2, "-Rl", NULL};
    execvp(path2, buf); // e

    return 0;
}
/*
Output:
.:
total 160
-rw-r--r-- 1 jeevesh jeevesh    50 Sep  7 17:10 22_sample.txt
drwxr-xr-x 2 jeevesh jeevesh  4096 Aug 15 13:47 Documents
-rw-r--r-- 1 jeevesh jeevesh     0 Aug 15 13:50 Sample_hardlink.txt
-rw-r--r-- 1 jeevesh jeevesh   197 Aug 16 06:26 Sample_softlink.c.save
lrwxrwxrwx 1 jeevesh jeevesh    10 Aug 15 13:52 Sample_softlink.txt -> sample.txt
-rwxr-xr-x 1 jeevesh jeevesh 15968 Aug 28 17:10 a.out
-rwxr-xr-x 1 jeevesh jeevesh 16032 Sep  7 16:55 check
-rw-r--r-- 1 jeevesh jeevesh   207 Sep  7 16:55 check.c
-rwxr-xr-x 1 jeevesh jeevesh 15776 Aug 28 18:02 output.out
-rwxr-xr-x 1 jeevesh jeevesh 16264 Sep  7 17:10 part
-rw-r--r-- 1 jeevesh jeevesh   415 Sep  7 17:10 part2.c
-rwxr-xr-x 1 jeevesh jeevesh 16184 Sep  7 17:13 q27
-rw-r--r-- 1 jeevesh jeevesh   433 Sep  7 17:13 q27.c
-rw-r--r-- 1 jeevesh jeevesh   266 Aug 28 18:28 q3.c
-rwxr-xr-x 1 jeevesh jeevesh 16088 Aug 28 18:28 q3.out
-rw-r--r-- 1 jeevesh jeevesh     9 Aug 28 18:29 q3_created
-rw-r--r-- 1 jeevesh jeevesh   228 Aug 28 18:45 q4.c
-rwxr-xr-x 1 jeevesh jeevesh 16000 Aug 28 18:45 q4.out
-rw-r--r-- 1 jeevesh jeevesh     0 Aug 28 18:43 q4_open.txt
-rw------- 1 jeevesh jeevesh    16 Aug 28 18:52 q5.c.save
drwxr-xr-x 2 jeevesh jeevesh  4096 Sep  6 17:02 ss_work
-rw-r--r-- 1 jeevesh jeevesh   103 Aug 28 18:02 test_q2.c

./Documents:
total 0

./ss_work:
total 0
lrwxrwxrwx 1 jeevesh jeevesh 9 Sep  6 17:02 softlink_to_file1 -> file1.txt
*/
