#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[4];
} FITNESS_DATA;

// Define any additional variables here
int endreach = 0;
int count = 0;
char record[50];
char datetoken[50];
char timetoken[50];
char stepstoken[50];


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
    FILE *pointer;
    pointer = fopen("FitnessData_2023.csv", "r");

    FITNESS_DATA data[100];

    while(endreach == 0)
    {
        count= count+1;
        fgets(record, 50, pointer);
        tokeniseRecord(record, ",", datetoken, timetoken, stepstoken);
        strcpy(data[count].date, datetoken);
        strcpy(data[count].time, timetoken);
        strcpy(data[count].steps, stepstoken);
        if(record == "\n")
        {
            endreach == 1;
        }
    }

    fclose(pointer);

}
