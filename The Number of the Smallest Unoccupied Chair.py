class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        chair, temp, target = 0, 0, times[targetFriend]
        chair_taken, chair_free = [], []
        times = sorted(times, key=lambda x: x[0])
        
        for start, end in times:
            while chair_taken and chair_taken[0][0] <= start:
                heapq.heappush(chair_free, heapq.heappop(chair_taken)[1])    
            if chair_free:
                temp = heapq.heappop(chair_free)
                heapq.heappush(chair_taken, [end, temp])     
            else:
                temp = chair
                heapq.heappush(chair_taken, [end, chair])
                chair += 1
            if start == target[0]: return temp
