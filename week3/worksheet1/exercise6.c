#include <stdio.h>

int main()
{
    int num = -50;
    while(num != -1 || num < 0 || num > 100)
    {
        printf("Enter num:\n");
        scanf("%d", &num);
    }
    if(num == 0)
    {
        printf("Loop terminated");
    }
    else
    {
        printf("Num is valid");
    }
    return 0;
}