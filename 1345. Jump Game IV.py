class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)

        if n == 1:
            return 0

        graph = defaultdict(list)

        for i, val in enumerate(arr):
            graph[val].append(i)

        q = deque([0])
        visited = [False] * n
        visited[0] = True

        steps = 0

        while q:
            for _ in range(len(q)):
                idx = q.popleft()

                if idx == n - 1:
                    return steps

                if idx - 1 >= 0 and not visited[idx - 1]:
                    visited[idx - 1] = True
                    q.append(idx - 1)

                if idx + 1 < n and not visited[idx + 1]:
                    visited[idx + 1] = True
                    q.append(idx + 1)

                if arr[idx] in graph:
                    for nxt in graph[arr[idx]]:
                        if not visited[nxt]:
                            visited[nxt] = True
                            q.append(nxt)

                    del graph[arr[idx]]

            steps += 1

        return -1       
