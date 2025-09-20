/*
============================================================================
Name : 08.c
Author : Jeevesh Rai
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 24th Aug, 2025.
============================================================================
*/
#include <sys/types.h> // Import for open system call.
#include <sys/stat.h>  // Import micros
#include <fcntl.h>     // Import File Control
#include <unistd.h>    // Import for read and write system call
#include <stdio.h>     // Import for perror and printf functions

int main(int argc, char *argv[]){
    if(argc <= 1){
        perror("Please enter File Name\n");
        return 0;
    }

    int sourceFD = open(argv[1], O_RDONLY);
    if(sourceFD == -1){
        perror("Error opening file\n");
        return 0;
    }

    char buffer[1];  // read one char at a time
    int readByte, writeByte;

    while((readByte = read(sourceFD, buffer, 1)) > 0){
        writeByte = write(STDOUT_FILENO, buffer, readByte);
        if(writeByte == -1){
            perror("Error while printing\n");
            close(sourceFD);
            return 0;
        }
    }

    if(readByte == -1){
        perror("Error in reading from File\n");
    }

    close(sourceFD);
    return 0;
}

/*
./a.out 01_a.c
*/
