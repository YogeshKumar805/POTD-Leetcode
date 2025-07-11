import heapq

class Solution:
    def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
        meetings.sort(key=lambda x: x[0])
        free = list(range(n))
        heapq.heapify(free)
        busy = []
        cnt = [0]*n
        for start, e in meetings:
            while busy and busy[0][0] <= start:
                _, r = heapq.heappop(busy)
                heapq.heappush(free, r)
            dur = e - start
            if free:
                r = heapq.heappop(free)
                end = e
            else:
                t, r = heapq.heappop(busy)
                end = t + dur
            cnt[r] += 1
            heapq.heappush(busy, (end, r))
        m = max(cnt)
        for i, val in enumerate(cnt):
            if val == m:
                return i
