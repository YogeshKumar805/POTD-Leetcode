class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        count = 0
        mod_count = {0: 1}  # Initialize with 0:1 to handle the case where the prefix sum itself is divisible by k
        
        for num in nums:
            prefix_sum += num
            mod = prefix_sum % k
            
            # If mod is negative, convert it to a positive equivalent
            if mod < 0:
                mod += k
            
            # If mod is in the hashmap, it means we have seen this mod value before
            if mod in mod_count:
                count += mod_count[mod]
            
            # Update the count of this mod value in the hashmap
            if mod in mod_count:
                mod_count[mod] += 1
            else:
                mod_count[mod] = 1
        
        return count
