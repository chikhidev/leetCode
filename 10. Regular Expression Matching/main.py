class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        str_len = len(s)
        express_len = len(p)

        if str_len == 0: return (express_len == str_len)

        expres_idx = 0
        curr_char = p[0]
        allow_multi = False
        prev_checked = False

        if (expres_idx < (express_len - 1) and p[expres_idx + 1] == '*'):
            expres_idx += 1
            allow_multi = True


        i = 0
        while i < str_len:
            char = s[i]

            if ((char == curr_char) or (curr_char == '.')) and allow_multi:
                i += 1
                continue

            if char != curr_char and curr_char != '.':
                if prev_checked:
                    return False
                prev_checked = True
            else:
                prev_checked = False
                i += 1

            if expres_idx == (express_len - 1) and i < str_len:
                return False

            if expres_idx < (express_len - 1):
                curr_char = p[expres_idx + 1]
                expres_idx += 1

            if (expres_idx < (express_len - 1) and p[expres_idx + 1] == '*'):
                expres_idx += 1
                allow_multi = True
            else:
                allow_mutli = False

        return True


if __name__ == "__main__":
    s = Solution()
    result = s.isMatch("mississippi", "mis*is*p*.")
    print(result)
