#include <stdio.h>

int main(){
    char *filename = "challenge.txt";
    int howmany;
    int numarray[50];
    int i=0;
    int total;
    int mean;

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    printf("How many numbers: \n");
    scanf("%d", &howmany);

    for(i=0; i<howmany; i++){
        scanf("%d", &numarray[i]);
        total += numarray[i];
        fprintf(file, "%d\n", numarray[i]);
    }

    mean = total/howmany;
    fprintf(file, "%d\n", mean);

    return 0;
    
}