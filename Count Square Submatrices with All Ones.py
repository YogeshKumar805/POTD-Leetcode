class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        ans = sum(matrix[0])
        for i in range(1, n):
            ans += matrix[i][0]
            for j in range(1, m):
                if matrix[i][j]:
                    matrix[i][j] += min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j])
                    ans += matrix[i][j]
        return ans   
