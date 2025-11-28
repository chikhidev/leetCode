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
            should_be_ignored = False

            print("Iteration:", i, "curr_char:", curr_char, "allow_multi:", allow_multi, "char:", char, "should be ignored:", should_be_ignored)

            if ((char == curr_char) or (curr_char == '.')) and allow_multi:
                i += 1
                continue
            elif char != curr_char and allow_multi:
                should_be_ignored = True

            if char != curr_char and curr_char != '.':
                if not should_be_ignored and prev_checked:
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
                print("Toggled allow_multi to be False")
                allow_mutli = False

        return True


if __name__ == "__main__":
    s = Solution()
    #result = s.isMatch("b", "c*a*b")
    result = s.isMatch("mississippi", "mis*is*p*.")
    print(result)
