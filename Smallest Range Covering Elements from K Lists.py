import heapq

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        # Min-heap to track the smallest element across all lists
        min_heap = []
        current_max = float('-inf')  # Track the current largest element in the window
        
        # Initialize the heap with the first element from each list
        for i in range(len(nums)):
            heapq.heappush(min_heap, (nums[i][0], i, 0))  # (value, list_index, element_index)
            current_max = max(current_max, nums[i][0])  # Update the max value
        
        # Initialize the result range to a very large one
        result_range = [-10**5, 10**5]
        
        while min_heap:
            current_min, list_idx, elem_idx = heapq.heappop(min_heap)  # Pop the smallest element
            
            # Check if the current range [current_min, current_max] is smaller
            if current_max - current_min < result_range[1] - result_range[0]:
                result_range = [current_min, current_max]
            
            # If we have reached the end of one of the lists, break the loop
            if elem_idx + 1 == len(nums[list_idx]):
                break
            
            # Otherwise, push the next element from the same list into the heap
            next_elem = nums[list_idx][elem_idx + 1]
            heapq.heappush(min_heap, (next_elem, list_idx, elem_idx + 1))
            
            # Update the max value
            current_max = max(current_max, next_elem)
        
        return result_range
