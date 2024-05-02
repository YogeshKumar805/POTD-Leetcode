class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        # Initialize a set to store the absolute values of negative numbers
        neg_abs = set()
        
        # Loop through the numbers and insert the absolute values of negative numbers into the set
        for num in nums:
            if num < 0:
                neg_abs.add(-num)
        
        max_k = -1
        
        # Iterate through the numbers to find the maximum positive integer
        for num in nums:
            # If current number is positive and its absolute value exists in the set
            if num > max_k and num in neg_abs:
                max_k = num
        
        return max_k
