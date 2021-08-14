#include <stdlib.h>
#include <stdio.h>

#include "readterminal.h"


char* read_string_from_terminal()//reads a string of variable length and returns a pointer to it
{
	size_t length = 0; //counts number of characters
	char *input = malloc(1);
	int c;

	input = (char *) malloc(sizeof(char)); //Allocate initial memory

	if(input == NULL) //Fail if allocating of memory not possible
	{
		printf("Could not allocate memory!");
		exit(EXIT_FAILURE);
	}

	while((c = getchar()) != '\n' && c != EOF) {
		char *t = realloc(input, length + 1);
		input = t;
		input[length++] = c;
	}

	input[length] = '\0'; //add terminator
	return input;
}
