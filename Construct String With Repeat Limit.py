class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        pq = [(-ord(k), v) for k, v in Counter(s).items()] 
        heapify(pq)
        ans = []
        while pq: 
            k, v = heappop(pq)
            if ans and ans[-1] == k: 
                if not pq: break 
                kk, vv = heappop(pq)
                ans.append(kk)
                if vv-1: heappush(pq, (kk, vv-1))
                heappush(pq, (k, v))
            else: 
                m = min(v, repeatLimit)
                ans.extend([k]*m)
                if v-m: heappush(pq, (k, v-m))
        return "".join(chr(-x) for x in ans)
