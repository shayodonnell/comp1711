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
char record[22]; //Record currently being read in is stored here
int count=0; // Keeps track of the number of records being read in
char datereturn[11];
char timereturn[6];
char stepsreturn[5];
int stepsreturnint;

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
    //declare our array of structs
    FITNESS_DATA data[60];

    //open csv file
    FILE *fitnessfile;
    fitnessfile = fopen("FitnessData_2023.csv","r");

    while(fgets(record, 22, fitnessfile))
    {
        printf("Record: %s, Count: %d\n",record,count);

        tokeniseRecord(record, ",", datereturn, timereturn, stepsreturn);

        strcpy(data[count].date,datereturn);

        printf("date: %s\n",data[count].date);

        strcpy(data[count].time,timereturn);
        printf("time: %s\n",data[count].time);

        stepsreturnint = atoi(stepsreturn);
        data[count].steps = stepsreturnint;
        printf("steps: %d\n",data[count].steps);

        printf("\n%s,%s,%s",datereturn,timereturn,stepsreturn);

        count= count+1;
    }

    fclose(fitnessfile);

    printf("Number of records in file: %d\n", count);
    for(i=0; i<3; i++)
    {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}
