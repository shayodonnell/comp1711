
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

FITNESS_DATA data[60];
int count=0;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

int inputFilename(){
	char record[24];

	char datereturn[11];
	char timereturn[6];
	char stepsreturn[6];

	int stepsreturnint;

	char filenameInput[50];
	printf("Input filename	:\n");
	scanf("%s", filenameInput);
	FILE *fitnessfile;
	fitnessfile = fopen(filenameInput, "r");
	if(fitnessfile == NULL){
		printf("Error: Could not find or open the file.\n");
		exit(1);
	}
	while(fgets(record,24,fitnessfile) != NULL)
	{
		tokeniseRecord(record,",",datereturn,timereturn,stepsreturn);

		strcpy(data[count].date, datereturn);
		strcpy(data[count].time, timereturn);
		stepsreturnint = atoi(stepsreturn);
		data[count].steps = stepsreturnint;

		count=count+1;
	}
	printf("File successfully loaded.\n");
}

int recordCount(){
	return count;
}

#endif // FITNESS_DATA_STRUCT_H
