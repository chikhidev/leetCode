#include "main.h"

int tribonacci(int n){
    if (n==0) return 0;
    if (n > 37) n = 37;
    
    int *FAB = (int*)malloc((n + 1) * sizeof(int));
    int target, i = 0;

    FAB[0] = 0;
    FAB[1] = FAB[2] = 1;

    while (i < n){
        if (i >= 3)
            *(FAB + i) =  *(FAB + i - 1) + *(FAB + i - 2) + *(FAB + i - 3);
        i++;
    }

    target = *(FAB+ n);

    free(FAB);
    return target;
}


//T(n+3) = T(n) + T(n+1) + T(n+2)
//so:
//T(n) = - T(n+1) - T(n+2) + T(n+3)