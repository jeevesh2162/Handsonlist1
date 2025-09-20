
/*
============================================================================
Name : Q13.c
Author : Jeevesh Rai
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select)
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    struct timeval t;
    fd_set fd;
    
    FD_ZERO(&fd);        // initialize fd set
    FD_SET(0, &fd);      // add STDIN to fd set
    
    t.tv_sec = 10;
    t.tv_usec = 0;
    
    int a = select(1, &fd, NULL, NULL, &t);
    
    if (a == -1)
    {
        printf("Can't show output\n");
    }
    else if (a == 0)
    {
        printf("Time out occurred\n");
    }
    else
    {
        printf("Data entered\n");
    }

    return 0;
}

/*
Output:
Time out occurred  (was printed after 10 seconds if no input was given)
*/
