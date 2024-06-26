#include "main.h"

int main(){
    int goal = 10;
    
    while (goal >= 0){
        printf("%d\n", fib(goal));
        goal--;
    }

    return 0;
}