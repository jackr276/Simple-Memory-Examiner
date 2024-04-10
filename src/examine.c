/**
 * Author: Jack Robbins
 * This program acts as a simple "memory dumper" that prints out the memory addresses of the contents
 * passed through to this program in argv. All memory contents are printed out with 8-byte aligned & adjusted
 * addresses, for neantess
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>


/**
 * The main function simply takes in command line arguments, and makes appropriate calls to 
 * dumpPtrContents and dumpArgContents, passing in the needed paramaters. 
 */
int main(int argc, char** argv){
	//Predeclare prototypes of all needed functions
	void dumpPtrContents(void* ptr);
	void dumpArgContents(char* arg, int argLength);

	//First print out the argv pointer
	printf("\nargv    | ");
	//We want the address of argv, so use &
	dumpPtrContents(&argv);
	printf("\n");

	//Print out the address of every command line argument using the argv pointer
	for(int i = 0; i < argc; i++){
		printf("argv[%d] | ", i);
		//increment by i to iterate over the contents of the argv array
		//could also use &argv[i] -- same exact thing since &argv[i] = &(*(argv+i))
		dumpPtrContents(argv+i);
		printf("\n");
	}

	//Get the total length of all arguments, the dumpStringContents function needs this to know
	//exactly how much to print out
	int argLength = 0;
	for(int i = 0; i < argc; i++){
		//we want the entire size(null terminator included)
		argLength += strlen(argv[i]) + 1;
	}

	//Call the dumpArgContents function to handle printing the arguments
	dumpArgContents(*argv, argLength);

	return 0;
}


/**
 * This function prints out the contents(which are an address) contained in the pointer ptr
 * The parameter is of type void* to allow for the passing of any type of pointer that we'd like
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


/**
 * This function prints out the contents of the command line arguments(arg), that are of length
 * arglength. The function will adjust arg so that its memory address is 8-byte aligned(hex address
 * ends in 0 or 8) for neatness
 */
void dumpArgContents(char* arg, int argLength){
	//Calculate the adjustment factor -> this is how much we need to push back the arg ptr
	//to make it 8-byte aligned
	unsigned short adjustment = ((long long)arg) % 8;

	//Apply the adjustment constant to push arg back to the last 8-byte aligned address
	arg -= adjustment;
	//Adjust argLength by how much we pushed back the arg pointer
	argLength += adjustment;

	//Keep printing out 8 bytes until we exceed total arglength(some extra at the end is fine)
	for(int sum = 0; sum < argLength; sum+=8){
		printf("|");
	
		//On each iteration, print out 8 bytes, MSB first LSB last
		for(int j = 7; j > -1; j--){
			//Grab the byte that we want
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

	//increment arg by 8, since we've now iterated through 8 bytes(char = 1 byte)
	arg+=8;
	}
}

