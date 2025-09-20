/*
============================================================================
Name : Q19.c
Author : Jeevesh Rai
Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

// Function to read Time Stamp Counter
unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;

    start = rdtsc();   // before system call
    getpid();          // system call
    end = rdtsc();     // after system call

    printf("Cycles taken by getpid(): %llu\n", end - start);

    return 0;
}


// output
// Cycles taken by getpid(): 9109