class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        remainder_dict = {0: -1}  # Initializing with 0 to handle cases where the subarray itself is a multiple of k
        cum_sum = 0
        
        for i in range(len(nums)):
            cum_sum += nums[i]
            remainder = cum_sum % k
            
            if remainder in remainder_dict:
                if i - remainder_dict[remainder] > 1:  # Ensure the subarray length is at least 2
                    return True
            else:
                remainder_dict[remainder] = i
        
        return False
