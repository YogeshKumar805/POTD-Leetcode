from collections import deque

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        left = 0
        max_deque = deque()
        min_deque = deque()
        longest = 0
        
        for right in range(len(nums)):
            while max_deque and nums[max_deque[-1]] <= nums[right]:
                max_deque.pop()
            while min_deque and nums[min_deque[-1]] >= nums[right]:
                min_deque.pop()
            
            max_deque.append(right)
            min_deque.append(right)
            
            while nums[max_deque[0]] - nums[min_deque[0]] > limit:
                left += 1
                if max_deque[0] < left:
                    max_deque.popleft()
                if min_deque[0] < left:
                    min_deque.popleft()
            
            longest = max(longest, right - left + 1)
        
        return longest
