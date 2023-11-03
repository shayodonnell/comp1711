#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

char record[24];//stores record being read in

//Receive tokens
char datereturn[11];
char timereturn[6];
char stepsreturn[6];

int stepsreturnint;//converts stepsreturn to string

//counters
int count = 0;
int i=0;


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

    //Initialise struct. Only need 60 indexes, since record length is 59.
    FITNESS_DATA data[60];
    
    //read in csv file.
    FILE *fitnessfile;
    fitnessfile = fopen("FitnessData_2023.csv","r");

    while(fgets(record, 24, fitnessfile) != NULL)
    {
        tokeniseRecord(record,",",datereturn,timereturn,stepsreturn);

        strcpy(data[count].date, datereturn);

        strcpy(data[count].time, timereturn);

        stepsreturnint = atoi(stepsreturn);
        data[count].steps = stepsreturnint;

        count=count+1;
    }
    
    fclose(fitnessfile);

    printf("Number of records in file: %d\n", count);
    
    for(i=0; i<3; i++)
    {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}
