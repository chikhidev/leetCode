class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        vector<int> res;

        for (int i = 0; i < numsSize; i++) {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};