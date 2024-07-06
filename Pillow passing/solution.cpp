class Solution {
public:
    int passThePillow(int n, int time) {
        int16_t res = 0;
        int16_t row = time / (n - 1);

        if (row % 2 == 0) {
            res = time - row * (n - 1) + 1;
        } else {
            res = n - 1 - (time - row * (n - 1));
        }

        return res;
    }
};