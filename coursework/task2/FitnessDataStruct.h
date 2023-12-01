
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
void openFile(const char *filenameInput, FITNESS_DATA data[1024], int count);
char menu();
int readInFile(FITNESS_DATA data[1024]);
void fewestSteps(FITNESS_DATA data[1024]);
void largestSteps(FITNESS_DATA data[1024]);
int meanStepCount(FITNESS_DATA data[1024]);
void longestPeriodOverFiveHundred(FITNESS_DATA data[1024]);

#endif // FITNESS_DATA_STRUCT_H