#include <stdio.h>

int main(){
    FILE *pointer;
    pointer = fopen("FitnessData_2023.csv", "r");

    char string[22];

    while(fgets(string, 22, pointer) != NULL)
    {
        printf("%s", string);
    }
}