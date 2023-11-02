#include <stdio.h>


int main()
{
    //declare vars
    int n;
    int i=0;
    int square;
   
    //Creates file squares.dat
    FILE *pointer;
    pointer = fopen("squares.dat", "w");

    //receive number input from user
    printf("Enter number: \n");
    scanf("%d", &n);

    //calculate squares, write to file
    for (i=1; i<=n; i++)
    {
        square = i*i;
        fprintf(pointer,"%d\n",square);
    }
    
    //close file
    fclose(pointer);

    return 0;
}