class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels="aeiou"
        res=[]
        for i in words:
            if i[0] in vowels and i[-1] in vowels:
                res.append(1)
            else:
                res.append(0)
        prefix=[0]*(len(res)+1)
        for i in range(len(res)):
            prefix[i+1]=prefix[i]+res[i]
        ans=[]
        for l,r in queries:
            ans.append(prefix[r+1]-prefix[l])
        return ans
