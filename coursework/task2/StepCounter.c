#include <stdio.h>
#include "FitnessDataStruct.h"

int main()
{
    char optionSelected;
    char filename[50];
    int status;

    printf("Select from the following options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit\n");
    scanf("%c", optionSelected);
    if(optionSelected == "A")
    {
        printf("Input filename: ");
        scanf("%s", filename);
        status = fileread(filename);
        if (status == 1) {
            
        }
    }else if (optionSelected == "B")
    {
        /* code */
    }else if (optionSelected == "C")
    {
        /* code */
    }else if (optionSelected == "D")
    {

    }else if (optionSelected == "E")
    {

    }else if (optionSelected == "F")
    {

    }else if (optionSelected == "Q")
    {

    }else
    {
        printf("Error: invalid selection");
    }
    
    
}