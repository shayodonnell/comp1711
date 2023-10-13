#include <stdio.h>

int main(){
    int i;
    char mystring[6] = "hello";

    for(i=5; i>=0; i--){
        printf("%c\n", mystring[i]);
    }
}