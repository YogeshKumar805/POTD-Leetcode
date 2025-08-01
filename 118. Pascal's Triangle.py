class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        a=[[]]*numRows
        for i in range(numRows):
            a[i]=[1]*(i+1)
            for j in range(1,i//2+1):
                a[i][i-j]=a[i][j]=a[i-1][j-1]+a[i-1][j]
        return a
