class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        prefixModCount = {0: 1}
        prefixSum = 0
        result = 0
        
        for num in nums:
            if num % modulo == k:
                prefixSum += 1
            remainder = prefixSum % modulo
            target = (remainder - k) % modulo
            result += prefixModCount.get(target, 0)            
            prefixModCount[remainder] = prefixModCount.get(remainder, 0) + 1
        
        return result        
