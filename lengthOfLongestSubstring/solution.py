class Solution:
    def lengthOfLongestSubstring(self, string: str) -> int:
        # cdd
        # ^
        # ^
        longest = 0
        for i in range(len(string)):
            reminder = ""
            for j in range(i, len(string)):
                if reminder != "" and string[j] == reminder[0]:
                    break
                if string[j] in reminder:
                    break
                reminder += string[j]
            if len(reminder) > longest: longest = len(reminder)

        return longest