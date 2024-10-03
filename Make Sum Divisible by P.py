class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:

        total_sum = sum(nums)
        target_mod = total_sum % p

        if target_mod ==0:
            return 0
        
        if total_sum < p:
            return -1

        prefix_sum = 0
        mod_map = {0: -1}  
        min_length = len(nums)

        # Step 3: Traverse the array and calculate prefix sums modulo p
        for i, num in enumerate(nums):
            prefix_sum = (prefix_sum + num) % p
            
            # Calculate the required remainder to remove
            required_mod = (prefix_sum - target_mod) % p
            
            # Check if we've seen the required remainder before
            if required_mod in mod_map:
                min_length = min(min_length, i - mod_map[required_mod])
            
            # Store the current prefix sum modulo in the map
            mod_map[prefix_sum] = i
        
        # Step 4: If no valid subarray is found, return -1
        return min_length if min_length < len(nums) else -1
