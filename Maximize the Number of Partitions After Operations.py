class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        n = len(s)
        cnt = [1 << (ord(i) - ord("a")) for i in s]
        @lru_cache(None)
        def dp(i, j, mask):
            if i == len(cnt): return 0
            mask2 = mask | cnt[i]
            if mask2.bit_count() > k:
                ans = 1 + dp(i + 1, j, cnt[i])
            else:
                ans = dp(i + 1, j, mask2)
            if j:
                for q in range(26):
                    mask2 = mask | (1 << q)
                    if mask2.bit_count() > k:
                        ans = max(ans, 1 + dp(i + 1, 0, 1 << q))
                    else:
                        ans = max(ans, dp(i + 1, 0, mask2))            
            return ans
        return dp(0, 1, 0) + 1
