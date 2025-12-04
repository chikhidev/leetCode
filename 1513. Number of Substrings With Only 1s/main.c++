#include <iostream>

using namespace std;
#define FACT 1000000007

class Solution {
public:
    int numSub(string s) {
        size_t total = 0;
        const size_t size = s.size();
        uint last = 0;
        uint curr = 1;

        for (size_t i = 0; i < size; i++) {
            if (s[i] == '1') {
                if (i > 0)
                    curr = last + 1;
                else
                    curr = 1;
                total += curr;
                last = curr;
            } else {
                last = 0;
            }
        }

        if (total > FACT) {
            return total % FACT;
        }

        return total;
    }
};