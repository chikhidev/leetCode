#include "main.h"

//[1,100,1,1,1,100,1,1,100,1]
//[10,1,1,1,1,100,1,1,100,1]

int minCostClimbingStairs(int* cost, int costSize){
    if(costSize == 0) return 0;
    if(costSize == 2) return cost[0];
    if(costSize == 3) return cost[1];

    int i, res = 0;

    if (cost[0] < cost[1]){
        i = 0;
        res += cost[0];
        printf("init with: %d\n", cost[0]);
    }
    else{
        i = 1;
        res += cost[1];
        printf("init with: %d\n", cost[1]);
    };
    //0, 1, 0, 1
    //^
    while (i < costSize){
        if(i + 2 < costSize && ((cost[i + 1] + cost[i + 2]) != 0 )){
            if (cost[i + 1] < cost[i + 2]){
                res += cost[i + 1];
                printf("%d less than %d\tres: %d\n", cost[i + 1], cost[i + 2], res);
            }else if (cost[i + 1] == cost[i + 2]){
                res += cost[i + 1];
                printf("%d =  %d\tres: %d\ti: %d\n", cost[i + 1], cost[i + 2], res, i);
                i++;
            }
            else{
                res += cost[i + 2];
                printf("%d less than %d\tres: %d\n", cost[i + 2], cost[i + 1], res);
            }
            i++;
        }
        else if (i + 1 < costSize && cost[i + 1] != 0){
            if (cost[i] != 0)
                res += cost[i + 1];
            printf("%d is the last one, res: %d\n", cost[i + 1], res);
        }
        i++;
    }
    return res;
}