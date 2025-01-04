class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = 0
        for c in set(s):  # Iterate over unique characters
            i, j = s.find(c), s.rfind(c)  # First and last occurrence
            if j > i + 1:  # Ensure there's at least one element between
                res += len(set(s[i+1:j]))  # Count unique middle elements
        return res
