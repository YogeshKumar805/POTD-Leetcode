class Solution:
    def countCoveredBuildings(self, n: int, b: List[List[int]]) -> int:
        rmax = [0] * (n + 1)
        rmin = [n + 1] * (n + 1)
        cmax = [0] * (n + 1)
        cmin = [n + 1] * (n + 1)

        # Track extreme buildings for each row and column
        for x, y in b:
            rmax[y] = max(rmax[y], x)
            rmin[y] = min(rmin[y], x)
            cmax[x] = max(cmax[x], y)
            cmin[x] = min(cmin[x], y)

        ans = 0

        # A building is covered only if it's strictly inside both extremes
        for x, y in b:
            if rmin[y] < x < rmax[y] and cmin[x] < y < cmax[x]:
                ans += 1

        return ans
