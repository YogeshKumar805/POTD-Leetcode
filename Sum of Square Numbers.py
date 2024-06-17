class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        s=set()
        for i in range( 0, floor(math.sqrt(c)+1)):
            s.add(i*i)
            if  c-i*i in s or 2*i*i==c:
                return True
        return False        
