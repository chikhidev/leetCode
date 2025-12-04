class Solution:
    def countCollisions(self, directions: str) -> int:
        size = len(directions)
        if size <= 1 :
            return 0

        res:int = 0
        last:str = directions[0]
        prev_effected = 1

        for i in range(1, size):
            if last == 'R' and directions[i] in ['L', 'S']:
                last = 'S'
                res += prev_effected
                if directions[i] == 'L':
                    res += 1
                prev_effected = 1
            elif last == 'S' and directions[i] == 'L':
                res += 1
                prev_effected = 1
            else:
                if last == 'R' and directions[i] == 'R':
                    prev_effected += 1
                last = directions[i]
        
        return res
        
if __name__ == "__main__":
    res = Solution().countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR")
    print(res)

        