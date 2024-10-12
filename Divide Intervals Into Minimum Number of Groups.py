class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        events = []
        
        # Create start and end events for each interval
        for interval in intervals:
            left, right = interval
            events.append((left, 1))   # Start of an interval
            events.append((right + 1, -1))  # End of an interval (right + 1 to handle inclusive overlap)
        
        # Sort events by time; in case of tie, end events (-1) should come before start events (1)
        events.sort()
        
        max_groups = 0
        current_groups = 0
        
        # Sweep through the events
        for _, event in events:
            current_groups += event  # Add 1 for start, subtract 1 for end
            max_groups = max(max_groups, current_groups)
        
        return max_groups
