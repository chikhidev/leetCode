#include "main.h"

int main(){
    int goal = 25;
    
    while (goal >= 0){
        printf("%d:\t%d\n", goal, tribonacci(goal));
        goal--;
    }

    return 0;
}