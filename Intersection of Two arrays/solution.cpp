struct Number {
    int value;
    int count1;
    int count2;

    Number(): value(-1), count1(0), count2(0){}
};

Number *collected(vector<Number*>&collector, int number) {
    for (auto num: collector) {
        if (num->value == number) return num;
    }
    return nullptr;
}


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<Number *>collector;
        vector<int>res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int iterLen;

        iterLen = len1;
        if (len2 > len1) {
            iterLen = len2;
        }
        for (int i = 0; i < iterLen; i++) {
            Number *collectedNumber;

            if (i < len1) {
                collectedNumber = collected(collector, nums1[i]);

                if (collectedNumber == nullptr) {
                    collectedNumber = new Number;
                    collectedNumber->value = nums1[i];
                    collectedNumber->count1 = 1;
                    collector.push_back(collectedNumber);
                } else {
                    collectedNumber->count1 += 1;
                }
            }
            if (i < len2) {
                collectedNumber = collected(collector, nums2[i]);

                if (collectedNumber == nullptr) {
                    collectedNumber = new Number;
                    collectedNumber->value = nums2[i];
                    collectedNumber->count2 = 1;
                    collector.push_back(collectedNumber);
                } else {
                    collectedNumber->count2 += 1;
                }
            }
        }

        for (auto collected_: collector) {
            if (collected_->count1 > 0 && collected_->count2 > 0) {
                int minC = min(collected_->count1, collected_->count2);
                for (int i = 0; i < minC; i++) {
                    res.push_back(collected_->value);
                }
            }
            delete collected_;
        }

        return res;
    }
};