class Solution:
    def romanToInt(self, s: str) -> int:
        set_:dict[str, int] = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        res:int = 0
        last = None

        for index, character in enumerate(s):
            took = set_.get(character)
            if took is not None:
                res += took
                if last is not None and last < took:
                    res -= 2 * last
                last = took
    
        return res

