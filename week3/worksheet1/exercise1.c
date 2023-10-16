#include <stdio.h>

int main(){
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    if(num > 0)
    {
        printf("%d is positive.\n", num);
    }else if(num < 0)
    {
        printf("%d is negative.\n", num);
    }else
    {
        printf("The value is zero.\n");
    }

    return 0;

}