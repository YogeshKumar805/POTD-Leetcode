class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        if k == 0:
            return 0
        cnt_all = Counter(s)
        if len(cnt_all) < 3 or any(c < k for c in cnt_all.values()):
            return -1
        cnt_excess = defaultdict(int)
        ans, left = 0, 0
        for right, ch in enumerate(s):
            cnt_excess[ch] += 1
            while cnt_all[ch] - cnt_excess[ch] < k:
                cnt_excess[s[left]] -= 1
                left += 1
            ans = max(right - left + 1, ans)
        return len(s) - ans
