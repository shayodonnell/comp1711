#include <stdio.h>

int main(){

    // declare vars
    int length;
    int width;
    int area;

    // receive length and width inputs from user
    printf("Enter length: ");
    scanf("%d", &length);

    printf("Enter width: ");
    scanf("%d", &width);

    // calculate area
    area = length * width;

    // print area
    printf("The area of the rectangle is %d\n",area);

    return 0;
}