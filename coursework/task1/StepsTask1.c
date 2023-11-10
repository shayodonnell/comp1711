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

//stores record being read in
char record[24];

//Receive tokens
char datereturn[11];
char timereturn[6];
char stepsreturn[6];

//converts stepsreturn to string
int stepsreturnint;

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

    //print number of records in file
    printf("Number of records in file: %d\n", count);
    
    //print first three records
    for(i=0; i<3; i++)
    {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}
