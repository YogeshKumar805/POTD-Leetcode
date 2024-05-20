class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def dfs(index, current_xor):
            # If we have considered all elements
            if index == len(nums):
                return current_xor
            
            # XOR sum including nums[index]
            include = dfs(index + 1, current_xor ^ nums[index])
            # XOR sum excluding nums[index]
            exclude = dfs(index + 1, current_xor)
            
            # Sum of both cases
            return include + exclude
        
        # Start the recursion with the first element and initial XOR sum as 0
        return dfs(0, 0)
        
