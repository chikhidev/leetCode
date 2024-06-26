class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
       
        

        if (n % 2 == 0) {
            return myPow(x, n / 2) * myPow(x, n / 2);
        } else {
            if (n > 0) {
                return x * myPow(x, n / 2) * myPow(x, n / 2);
            } else {
                return (1 / x) * myPow(x, n / 2) * myPow(x, n / 2);
            }
        }
    }
};