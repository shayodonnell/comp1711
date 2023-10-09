#include <stdio.h>

int main(){
    // setting up 15 slots of memory for a string
    char name[15];
    
    // prompting user
    printf("Hello, please enter your name: \n");

    // receive user input, store in name
    scanf("%s", name);

    // print
    printf("Your name is %s\n", name);
}