class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        a = b = -1 # indices for first and second dif in strings
        for i in range(len(s1)):
            if s1[i] != s2[i]: 
                if a == -1: a = i # first char dif
                elif b == -1: b = i # second char dif
                else: return False # can't have more than 2 difs
        
        # either no difs found or swap is valid
        return (a == -1 and b == -1) or (s1[a] == s2[b] and s1[b] == s2[a])        
