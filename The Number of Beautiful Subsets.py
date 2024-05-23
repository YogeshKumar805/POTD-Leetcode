class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def backtrack(start, current_subset):
            nonlocal count
            
            # Only count non-empty subsets
            if current_subset:
                count += 1
            
            for i in range(start, len(nums)):
                # Check if current element nums[i] can be added to the current_subset
                can_add = True
                for num in current_subset:
                    if abs(num - nums[i]) == k:
                        can_add = False
                        break
                        
                if can_add:
                    # Include nums[i] in the subset and proceed
                    current_subset.append(nums[i])
                    backtrack(i + 1, current_subset)
                    # Backtrack: remove the last added element
                    current_subset.pop()
        
        nums.sort()  # Sorting to make the checking more efficient
        count = 0
        backtrack(0, [])
        return count
        
