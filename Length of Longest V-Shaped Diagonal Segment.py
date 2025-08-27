class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:        
        @lru_cache(None)
        def dfs(row,col, dr,dc, element, hasTurned):
            if not (0 <= row < m and 0 <= col < n) or grid[row][col] != element:
                return 0            
            ans = dfs(row + dr, col + dc, dr, dc, element^2, hasTurned)
            if hasTurned: return ans + 1
            length = dfs(row + dc, col - dr, dc, -dr, element^2, True)
            return max(ans,length) + 1 
        m, n = len(grid), len(grid[0])
        ans, dr, dc, hasOne = 0, 1, 1, False 
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    hasOne = True
                    for _ in range(4):
                        dr, dc = -dc, dr
                        vee = dfs(row + dr, col + dc, dr, dc, 2, False)
                        ans = max(ans, vee)
        return ans + hasOne
