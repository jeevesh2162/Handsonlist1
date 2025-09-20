/*
============================================================================
Name : 01_b.c
Author : Jeevesh Rai
Description : Create a hard link file using the `link` system call
Date: 22nd Aug, 2025.
============================================================================
*/

#include<unistd.h>	// Import link
#include<stdio.h>	// Import printf and perror

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Enter target and source file Name\n");
		return 0;
	}
	const char *source = argv[1];
	const char *target = argv[2];
	
	int status = link(source,target);

	if(status == -1){
		perror("Error while creating hard link\n");	
	}else{
		printf("Hard Link created successfully\n");
	}

	return 0;
}

/*
./a.out source.txt hardLink 
Hard Link created successfully
*/
