#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
int recordCount=0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
    FITNESS_DATA data[1024];
    while(1){
        switch(menu()){
            case 'A':
            case 'a':
                recordCount = readInFile(data);
                break;
            case 'B':
            case 'b':
                printf("Total records: %d\n", recordCount);
                break;
            case 'C':
            case 'c':
                fewestSteps(data);
                break;
            case 'D':
            case 'd':
                largestSteps(data);
                break;
            case 'E':
            case 'e':
                printf("Mean step count: %d\n", meanStepCount(data));
                break;
            case 'F':
            case 'f':
                longestPeriodOverFiveHundred(data);
                break;
            case 'Q':
            case 'q':
                return 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
   }
}

char menu(){
    char selectedOption;
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit\n");
    printf("Enter Choice: ");
    scanf(" %c",&selectedOption);
    return selectedOption;
}

int readInFile(FITNESS_DATA data[1024]){
    char record[24];

    char datereturn[11];
    char timereturn[6];
    char stepsreturn[6];

    int stepsreturnint;

    int count=0;

    char fileInput[50];

    printf("Enter filename: \n");
    scanf("%s", fileInput);
    
    //read in csv file.
    FILE *fitnessfile;
    fitnessfile = fopen(fileInput,"r");
    if(fitnessfile == NULL){
		printf("Error: Could not find or open the file.\n");
		exit(1);
	}

    //fetches each line
    while(fgets(record, 24, fitnessfile) != NULL)
    {
        //tokenise
        tokeniseRecord(record,",",datereturn,timereturn,stepsreturn);

        //insert into array
        strcpy(data[count].date, datereturn);
        strcpy(data[count].time, timereturn);
        stepsreturnint = atoi(stepsreturn);
        data[count].steps = stepsreturnint;

        //incrememnt count
        count=count+1;
    }
    
    //close file
    fclose(fitnessfile);

    printf("File successfully loaded.\n");

    return count;
}

void fewestSteps(FITNESS_DATA data[1024]){
    int count = 0;
    int lowestRecord = 0;
    while(data[count].steps != 0 && count < recordCount){
        if(data[count].steps < data[lowestRecord].steps){
            lowestRecord = count;
        }
        count = count +1;
    }
    printf("Fewest steps: %s %s\n", data[lowestRecord].date,data[lowestRecord].time);
}

void largestSteps(FITNESS_DATA data[1024]){
    int count = 0;
    int highestRecord = 0;
    while(data[count].steps != 0 && count < recordCount){
        if(data[count].steps > data[highestRecord].steps){
            highestRecord = count;
        }
        count = count +1;
    }
    printf("Largest steps: %s %s\n", data[highestRecord].date,data[highestRecord].time);;
}

int meanStepCount(FITNESS_DATA data[1024]){
    int count=0;
    int total = 0;
    while(data[count].steps !=0 && count < recordCount){
        total = data[count].steps + total;
        count = count + 1;
    }
    float meanExact = (float)total/recordCount;
    int meanRounded = round(meanExact);
    return meanRounded;
}

void longestPeriodOverFiveHundred(FITNESS_DATA data[1024]){
    int count = 0;
    int run = 0;
    int runCount = 0;
    int startPoint = 0;
    int endPoint = 0;
    int longestRunCount = 0;
    int longestStartPoint = 0;
    int longestEndPoint = 0;
    while(data[count].steps !=0 && count < recordCount){
        if(data[count].steps > 500){
            if(runCount == 0){
                startPoint = count;
            }
            runCount = runCount + 1;
        }
        else{
            if(runCount !=0){
                endPoint = count - 1;
                if(runCount > longestRunCount){
                    longestStartPoint = startPoint;
                    longestEndPoint = endPoint;
                    longestRunCount = runCount;
                }
                runCount = 0;
            }
        }
        count = count + 1;
    }
    printf("Longest period start: %s %s\n", data[longestStartPoint].date, data[longestStartPoint].time);
    printf("Longest period end: %s %s\n", data[longestEndPoint].date, data[longestEndPoint].time);
}