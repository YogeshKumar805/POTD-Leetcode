class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        result = [set() for _ in range(n)]
        indegrees = [0] * n
        adj_list = collections.defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)
            indegrees[v] += 1
        queue = deque()
        for i in range(len(indegrees)):
            if not indegrees[i]:
                queue.append(i)
        while queue:
            node = queue.popleft()
            for neighbor in adj_list[node]:
                result[neighbor].update(result[node], [node])
                indegrees[neighbor] -= 1
                if not indegrees[neighbor]:
                    queue.append(neighbor)
            result[node] = sorted(result[node])
        return result
