from collections import defaultdict
class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        G = defaultdict(list)
        for u,v in edges:
            G[u].append(v)
            G[v].append(u)
        components = 1
        def dfs(v, u):
            nonlocal components
            res = values[v]
            for w in G[v]:
                if w != u:
                    cur = dfs(w, v)
                    res += cur
                    if cur%k == 0:
                        components += 1
            return res
        dfs(0, -1)
        return components
