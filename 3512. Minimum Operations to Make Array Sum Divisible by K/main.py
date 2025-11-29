class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        total_sum: Number = sum(nums)
        return total_sum % k
