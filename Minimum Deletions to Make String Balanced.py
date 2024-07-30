class Solution:
    def minimumDeletions(self, s: str) -> int:
        bCount = 0
        minDeletions = 0
        for char in s:
            if char == 'a':
                minDeletions = min(minDeletions + 1, bCount)
            else:
                bCount += 1   
        return minDeletions
