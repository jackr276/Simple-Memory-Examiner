/**
 * Author: Jack Robbins
 * 04/05/2024
 * Homework 06 - only problem(argv memory content examiner)
 */

#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv){
	void dumpPtrContents(void* ptr);

	//First print out the argv pointer
	printf("\nargv    | ");
	dumpPtrContents(&argv);
	printf("\n");

	for(int i = 0; i < argc; i++){
		printf("argv[%d] | ", i);
		dumpPtrContents(&argv[i]);
		printf("\n");
	}

	return 0;
}


void dumpPtrContents(void* ptr){	
	//cast to unsigned char* to allow for dereferencing	
	unsigned char* ptrCpy = (unsigned char*)ptr;
	
	//Go through the pointer byte by byte, starting at the MSB
	for(int i = 7; i > -1; i--){
		printf("%02hhx ", *(ptrCpy + i));
	}
	
	printf("| %p\n", ptr);
}

