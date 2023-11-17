
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

int inputFilename(){
	char filenameInput[50];
	printf("Input filename	:\n");
	scanf("%s", filenameInput);
	FILE *filepointer;
	filepointer = fopen(filenameInput, "r");
	if(filepointer == NULL){
		printf("Error: Could not open file\n");
		exit(1);
	}
}

#endif // FITNESS_DATA_STRUCT_H
