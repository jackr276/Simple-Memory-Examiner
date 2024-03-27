/**
 * Author: Jack Robbins
 * 04/05/2024
 * Homework 06 - only problem(argv memory content examiner)
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv){
	//Predeclare prototypes of all needed functions
	void dumpPtrContents(void* ptr);
	void dumpStringContents(char* arg, int argLength);

	//First print out the argv pointer
	printf("\nargv    | ");
	dumpPtrContents(&argv);
	printf("\n");

	for(int i = 0; i < argc; i++){
		printf("argv[%d] | ", i);
		dumpPtrContents(&argv[i]);
		printf("\n");
	}

	//Get the total length of all arguments, the dumpStringContents function needs this to know
	//exactly how much to print out
	int argLength = 0;
	for(int i = 0; i < argc; i++){
		//Add the length of the string plus 1 for the null character
		argLength += strlen(argv[i]) + 1;
	}

	//Call the dumpStringContents function to handle printing the arguments
	dumpStringContents(*argv, argLength);

	return 0;
}


/**
 * Prints out the contents(which are an address) contained in the pointer ptr
 */
void dumpPtrContents(void* ptr){	
	//cast to unsigned char* to allow for dereferencing	
	unsigned char* ptrCpy = (unsigned char*)ptr;
	
	//Go through the pointer byte by byte, starting at the MSB
	for(int i = 7; i > -1; i--){
		printf("%02hhx ", *(ptrCpy + i));
	}
	//print out the address of ptr at the end	
	printf("| %p\n", ptr);
}

void dumpStringContents(char* arg, int argLength){
	//perform initial adjustment to make sure arg is 8-Byte aligned
	unsigned short nibble = (long long)arg & 0xF;
	//Push to the last 8-byte aligned address
	arg -= (nibble % 8);

	for(int sum = 0; sum <= argLength + argLength % 8; sum+=8){
		printf("|");
		
		for(int j = 7; j > -1; j--){
			unsigned char BYTE = *(arg + j);
			//Print out hexadecimal version of BYTE
			printf("%02hhx(", BYTE);

			//If byte is char printable, print the char. Otherwise print int version
			if(isprint(BYTE)){
				printf("%c", BYTE);
			} else {
				printf("\\%d", BYTE);
			}

			printf(") ");
		}
	
	//Print out the address of arg at the very end
	printf(" | %p\n\n", arg);

	//increment arg by 8
	arg+=8;
	}
}

