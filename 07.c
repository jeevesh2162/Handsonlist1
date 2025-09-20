/*
 = =*==========================================================================
 Name : 7.c

 Author : Keevesh Rai

 Description : Write a program to copy file1 into file2 ($cp file1 file2).

 Date: 6 September, 2025.
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char *source = "sample_file.txt";
    char *target = "new_sample.txt";

    int fd1, fd2;

    fd1 = open(source, O_RDONLY| _CREAT);
    fd2 = open(target, O_RDWR | O_CREAT, 0644);

    char buff;

    printf("Copying %s to %s .. ",source, target);

    while(read(fd1, &buff,1)!= '\0'){
        write(fd2, &buff, 1);
    }

    printf("File copied succesfully \n");

    close(fd1);
    close(fd2);

    return 0;

}
/*
 = =*==========================================================================

 ❯ gcc 7.c && ./a.out
 Copying sample_file.txt to new_sample.txt .. File copied succesfully
 ❯ cat sample_file.txt
 Writing to the file from test16.c
 Writing to the file from test16.c
 Writing to the file from test16.c
 Writing to the file from test16.c
 Writing to the file from test16.c
 ❯ cat new_sample.txt
 Writing to the file from test16.c
 Writing to the file from test16.c
 Writing to the file from test16.c
 Writing to the file from test16.c
 Writing to the file from test16.c



 ============================================================================
 */