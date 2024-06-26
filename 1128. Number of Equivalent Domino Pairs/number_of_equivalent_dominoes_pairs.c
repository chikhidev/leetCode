#include <stdio.h>
#include <stdlib.h>

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int pairs = 0;
    int hash[100] = {0};
    for (int i = 0; i < dominoesSize; i++){
        int v = dominoes[i][0] > dominoes[i][1] ?
                dominoes[i][0] * 10 + dominoes[i][1] :
                dominoes[i][1] * 10 + dominoes[i][0];
        pairs += hash[v]++;
    }
    return pairs;
}

int main() {
    int size = 4;
    int** d = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        d[i] = (int*)malloc(2 * sizeof(int));
    }

    d[0][0] = 1; d[0][1] = 2;
    d[1][0] = 2; d[1][1] = 1;
    d[2][0] = 3; d[2][1] = 4;
    d[3][0] = 5; d[3][1] = 6;

    int pairs = numEquivDominoPairs(d, size, NULL);
    printf("pairs: %d\n", pairs);

    for (int i = 0; i < size; i++) {
        free(d[i]);
    }
    free(d);

    return 0;
}
