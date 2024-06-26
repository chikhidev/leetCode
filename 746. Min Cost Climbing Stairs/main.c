#include "main.h"

int main() {
    int cost1[] = {0, 1, 0, 1};
    int costSize1 = sizeof(cost1) / sizeof(cost1[0]);
    int result1 = minCostClimbingStairs(cost1, costSize1);
    printf("Minimum cost for cost1: %d\n", result1);

    int cost2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int costSize2 = sizeof(cost2) / sizeof(cost2[0]);
    int result2 = minCostClimbingStairs(cost2, costSize2);
    printf("Minimum cost for cost2: %d\n", result2);

    return 0;
}