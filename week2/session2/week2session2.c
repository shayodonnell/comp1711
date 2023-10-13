#include <stdio.h>

int main(){
    int a=0, i=0;

    for(i=1; i<5; i++){
        printf("%d\n", i);
    }

    while(a<5){
        printf("%d\n",a);
        a = a+1;
    }
    return 0;
}