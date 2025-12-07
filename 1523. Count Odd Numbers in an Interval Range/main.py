class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return int(
            1
            + (1 if low % 2 != 0 else 0)
            + ((high - low - 1 - (1 if high % 2 == 0 else 0)) / 2)
        )
