#include "main.h"

int fib(int n){
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int fb[n + 1];
    int i = 2;
    fb[0] = 0;
    fb[1] = fb[2] = 1;

    while (i < (n + 1)) {
        fb[i] = fb[i -1] + fb[i - 2];
        i++;
    }

    return fb[n];
}

//0,1,1,2,3,5,8