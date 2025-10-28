class Solution:
    def countValidSelections(self, nums: List[int]) -> int:

        pref = list(accumulate(nums, initial = 0))
        n, ans, sm = len(nums), 0, pref[-1]

        for num, p in zip(nums, pref):
            p*= 2

            if num: continue
            if sm == p: ans+= 2
            if abs(sm - p) == 1: ans+= 1
        
        return ans
