class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        for i in range(1, len(nums)):
            if nums[i-1] % 2 == nums[i] % 2:
                return False # adjacent nums are both odd or even
        return True # passed check
