class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n, m=len(matrix), len(matrix[0])
        col0, row0=set(), set()
        for i, row in enumerate(matrix):
            for j, x in enumerate(row):
                if x==0:
                    row0.add(i)
                    col0.add(j)
        for i in row0:
            for j in range(m):
                matrix[i][j]=0
        for j in col0:
            for i in range(n):
                matrix[i][j]=0
        
        
