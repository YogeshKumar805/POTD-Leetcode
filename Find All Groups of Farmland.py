class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        rows, cols = len(land), len(land[0])
        visit = set()

        def dfs(r, c, ans):
            if r < 0 or r == rows or c < 0 or c == cols or land[r][c] == 0 or (r, c) in visit:
                return []
            visit.add((r, c))

            group[0] = min(group[0], r)
            group[1] = min(group[1], c)
            group[2] = max(group[2], r)
            group[3] = max(group[3], c)

            dfs(r, c+1, group)
            dfs(r, c-1, group)
            dfs(r+1, c, group)
            dfs(r-1, c, group)

        result = []
        for r in range(rows):
            for c in range(cols):
                if land[r][c] == 1 and (r, c) not in visit:
                    group = [r, c, r, c]
                    dfs(r, c, group)
                    result.append(group)
                    
        return result
                    
