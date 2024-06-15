import heapq
from typing import List

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # Combine capital and profits into one list of tuples and sort by capital
        projects = sorted(zip(capital, profits))
        
        max_profit_heap = []
        current_capital = w
        project_index = 0
        
        for _ in range(k):
            # Push all projects that can be started with current_capital into the max heap
            while project_index < len(projects) and projects[project_index][0] <= current_capital:
                heapq.heappush(max_profit_heap, -projects[project_index][1])
                project_index += 1
            
            # If there are no projects that can be started, break
            if not max_profit_heap:
                break
            
            # Select the project with the maximum profit
            current_capital += -heapq.heappop(max_profit_heap)
        
        return current_capital
