/*
============================================================================
Name : Q17b.c
Author : Jeevesh Rai
Description : Online ticket reservation with write lock.
              Open the file, lock it, read ticket number, increment,
              print new number, update the file, unlock, and exit.
Date: 28th Aug, 2025.
============================================================================
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

struct ticket {
    int ticket_num;
};

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;   // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          // Lock whole file
    lock.l_pid = getpid();

    printf("Trying to acquire lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Locking failed");
        return 1;
    }
    printf("Lock acquired by PID %d\n", getpid());

    // Read current ticket
    struct ticket t;
    lseek(fd, 0, SEEK_SET);
    read(fd, &t, sizeof(t));

    printf("Current ticket: %d\n", t.ticket_num);

    // Increment ticket
    t.ticket_num++;

    // Move back and write updated value
    lseek(fd, 0, SEEK_SET);
    write(fd, &t, sizeof(t));

    printf("New ticket: %d\n", t.ticket_num);

    // Unlock file
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Unlocking failed");
    }
    printf("Lock released\n");

    close(fd);
    return 0;
}

// Trying to acquire lock...
// Lock acquired by PID 1873
// Current ticket: 0
// New ticket: 1
// Lock released