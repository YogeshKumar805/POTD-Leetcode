class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        count = 0 # tracks number of completed strings made

        def backtrack(i, chars):
            nonlocal count

            if i == n: 
                count += 1 # finished a string
                return "".join(chars) if count == k else "" # return string if it's k string, else ""
                
            for c in "abc": # a,b,c ensures lexicographical order
                if chars and chars[-1] == c: continue # prev char can't equal current

                res = backtrack(i + 1, chars + [c]) # add char and make rest of string
                if res:
                    return res # found k string

            return "" # never found k string
            
        return backtrack(0, [])
