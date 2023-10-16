#include <stdio.h>

int main(){
    int temp;
    printf("Enter temp: ");
    scanf("%d", &temp);

    if(temp < -10 || temp > 40)
    {
        printf("Invalid\n");
    }else
    {
        printf("Valid\n");
    }

    return 0;
}
