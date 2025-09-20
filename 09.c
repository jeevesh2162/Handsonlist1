/*
============================================================================
Name : 09.c
Author : Jeevesh Rai
Description : Write a program to print the following information about a given file - 
    1. Inode 
    2. Number of hard links 
    3. UID 
    4. GID 
    5. Size 
    6. Block size 
    7. Number of blocks 
    8. Time of last access 
    9. Time of last modification 
    10. Time of last change
Date: 7 sept, 2025.
============================================================================
*/
#include <sys/types.h> // for open(), stat()
#include <sys/stat.h>  // for stat structure
#include <fcntl.h>     // file control options
#include <unistd.h>    // for read(), write()
#include <stdio.h>     // for perror(), printf()
#include <time.h>      // for ctime()

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat statbuf;

    if (stat(argv[1], &statbuf) == -1) {
        perror("stat");
        return 1;
    }

    printf("Inode: %llu\n", (unsigned long long)statbuf.st_ino);
    printf("Number of hard links: %lu\n", (unsigned long)statbuf.st_nlink);
    printf("UID: %u\n", statbuf.st_uid);
    printf("GID: %u\n", statbuf.st_gid);
    printf("Size: %lld bytes\n", (long long)statbuf.st_size);
    printf("Block Size: %ld\n", (long)statbuf.st_blksize);
    printf("Number of Blocks: %lld\n", (long long)statbuf.st_blocks);

    printf("Last Access: %s", ctime(&statbuf.st_atime));
    printf("Last Modification: %s", ctime(&statbuf.st_mtime));
    printf("Time of Last Change: %s", ctime(&statbuf.st_ctime));

    return 0;
}

/*

Inode: 12466
Number of hard links: 1
UID: 1000
GID: 1000
Size: 50 bytes
Block Size: 4096
Number of Blocks: 8
Last Access: Sun Sep  7 17:10:56 2025
Last Modification: Sun Sep  7 17:10:44 2025
Time of Last Change: Sun Sep  7 17:10:44 2025
*/
