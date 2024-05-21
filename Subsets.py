from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        def backtrack(start, path):
            # Append the current subset to the result list
            result.append(path[:])
            
            # Iterate over the indices from 'start' to the end of 'nums'
            for i in range(start, len(nums)):
                # Include the number nums[i] in the current subset
                path.append(nums[i])
                # Recursively call backtrack to generate further subsets
                backtrack(i + 1, path)
                # Backtrack: remove the last element to explore the next subset
                path.pop()
        
        # Start backtracking with an empty path and starting index 0
        backtrack(0, [])
        
        return result
