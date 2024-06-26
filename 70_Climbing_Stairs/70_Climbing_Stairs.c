#include "main.h"

int climbStairs(int n){
    if (n <= 2) return n;

    int stairs[n+1], inc = 3;
    stairs[0] = 0;
    stairs[1] = 1;
    stairs[2] = 2;
    
    while (inc < (n + 1)){
        stairs[inc] = stairs[inc - 1] + stairs[inc - 2];
        inc++;
    }

    return stairs[n];
}