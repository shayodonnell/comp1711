#include <stdio.h>

typedef struct{
    double x;
    double y;
}point;

int main()
{
    point coordinates[10];
    
    int numimput;
    int i=0;
    for(i=0; i<10; i++)
    {
        printf("New coordinate\n");
        printf("Enter x coordinate: \n");
        scanf("%lf", &coordinates[i].x);
        printf("Enter y coordinate: \n");
        scanf("%lf", &coordinates[i].y);
    }
    for(i=0; i<10; i++)
    {
        printf("(%.2lf,%.2lf)\n", coordinates[i].x, coordinates[i].y);
    }
}