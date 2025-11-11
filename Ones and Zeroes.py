class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # Initialize dp with 0's
        dp = [[0] * (n+1) for _ in range(m+1)]
        
        # Iterate through each string in strs
        for s in strs:
            zero_count = s.count('0')
            one_count = s.count('1')
            
            # Update dp for each possible (i, j)
            for i in range(m, zero_count-1, -1):
                for j in range(n, one_count-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-zero_count][j-one_count] + 1)
        
        return dp[m][n]
