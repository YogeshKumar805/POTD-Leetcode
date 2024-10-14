class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        # Create a max heap by pushing negative values (to simulate max heap)
        max_heap = [-num for num in nums]
        heapq.heapify(max_heap)
        
        score = 0
        
        for _ in range(k):
            # Extract the largest element (invert the sign back to positive)
            max_elem = -heapq.heappop(max_heap)
            score += max_elem  # Add the value to the score
            
            # Compute the new value (ceil(max_elem / 3)) and push it back
            new_value = math.ceil(max_elem / 3)
            heapq.heappush(max_heap, -new_value)
        
        return score
