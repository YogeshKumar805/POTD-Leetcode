class Solution:
    def maxScore(self, s: str) -> int:
        zero=0
        one=0

        l=0
        r=0


        if s[0] and s[0]=='0':
            zero+=1
        for i in range(1,len(s)):
            if s[i]=='1':
                one+=1
        res=max(zero+one,0)
        while r<len(s)-2:
            r+=1
            
            if s[r]=='0':
                zero+=1
            elif s[r]=='1':
                one-=1
            res=max(zero+one,res)
            
        return(res)
                
