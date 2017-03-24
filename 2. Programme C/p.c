/**
	Character Stats 1.0.0 
	@author Francisco Javier Martinez Lago
	@license MIT

	A simple program that reads user input and keeps track of how many numerical, 
	alphabetical and special characters were entered by the user
**/

#include <stdio.h> 
#include <ctype.h> // Library needed to use getchar()

int main() {
	// We declare and initialize variables that will keep track of the characters to be entered by the user
	//int alphaCounter = 0, numCounter = 0, specialCounter = 0;

	typedef struct { 
		int alphaCounter;
		int numCounter;
		int specialCounter;
	} statBlock;

	statBlock statTracker;

	// We initialize the counters to 0
	statTracker.alphaCounter = statTracker.numCounter = statTracker.specialCounter = 0;

	printf("> "); // Makes entering input a bit cooler
	char in;
	
	// We read user input. If it's a stop signal like Control + D, then we immediately exit the loop
	// We ignore Line Return characters and Spaces
	// We detect what kind of character it is and we then increase the appropriate counter
	while ((in = (char) getchar()) != EOF) { 
			
			if (in == '\n' || in == ' ' ) {
				printf("> ");
				continue;
			} 
			else if (isalpha(in)) {
				statTracker.alphaCounter++;
			}
			else if (isdigit(in)) {
				statTracker.numCounter++;
			} 
			else {
				statTracker.specialCounter++;
			
		}
	}

	// We print out the statistics

	printf("\nStatistics\n##########\n");
	printf("Alphabetical characters: %d\n", statTracker.alphaCounter);
	printf("Numerical characters: %d\n", statTracker.numCounter);
	printf("Special characters: %d\n", statTracker.specialCounter);
}

