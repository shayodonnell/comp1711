#include <stdio.h>

int main() {

    int mark;

    printf("Enter mark:\n");
    scanf("%d", &mark);

    if (mark >= 70)
    {
        printf ("The mark of %d is a first\n", mark);
    }
    else if (mark >= 40){
        printf("The mark of %d is a pass\n", mark);
    }
    else{
        printf ("The mark of %d is a fail\n", mark);
    }

    return 0;
}