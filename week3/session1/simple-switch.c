#include <stdio.h>

int main() {
    int a = -1;
    while(a<0 || a>3){
        printf("Input number:");
        scanf("%d", &a);
    }
    switch (a)
    {
        case 0:     printf ("Option 0 has been selected\n");
        break;

        case 1:     printf ("Option 1 has been selected\n");
        break;

        case 2:     printf("Option 2 has been selected\n");
        break;

        case 3:     printf("Option 3 has been selected\n");
        break;

        default:    printf ("A different option has been selected\n");
    }
}