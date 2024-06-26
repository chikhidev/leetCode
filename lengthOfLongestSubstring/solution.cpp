# include <iostream>
# include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int longest = 0;
        string sub;

        for (int i = 0; i < n; i++) {
            sub = "";
            for (int j = i; j < n; j++) {
                if (sub != "" && s[j] == sub[0]) {
                    break;
                }
                if (sub.find(s[j]) != string::npos) {
                    break;
                }
                sub += s[j];
            }
            if (sub.size() > longest) {
                longest = sub.size();
            }
        }
        return longest;
    }
};