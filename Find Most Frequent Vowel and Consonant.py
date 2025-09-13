class Solution:
    def maxFreqSum(self, s: str) -> int:
        freq=Counter(s)
        maxCV=[0]*2
        for i, f in freq.items():
            idx=((1<<(ord(i)-97)) & 0x104111)!=0
            maxCV[idx]=max(maxCV[idx], f)
        return maxCV[0]+maxCV[1]
        
        
