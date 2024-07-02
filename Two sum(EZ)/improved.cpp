
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        vector<int> res(2);
        int prev = -1;
        int prevIndex = -1;
        int sumRes = 0;

        for (int i = numsSize - 1; i >= 0; i--) {
            if (nums[i] > target) continue;
            else {
                if (prev != -1) {
                    if (prev + nums[i] == target) {
                        res[0] = i;
                        res[1] = prevIndex;
                        return res;
                    }
                }
                prev = nums[i];
                prevIndex = i;
            }
        }
        return res;
    }
};