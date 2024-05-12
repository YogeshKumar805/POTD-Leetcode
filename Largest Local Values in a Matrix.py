class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        #initialize an empty list to store the resulting matrix
        res = []

        #iterate over each row of the grid, leaving last two rows
        for i in range(len(grid)-2):

            #append an empty list to res for the current row
            res.append([])

            #iterate over each column of the grid, leaaving last two columns 
            for j in range(len(grid[0])-2):

                #extract the curretn 3*3 submatrix and find the maximum value within it
                max_val = max(
                    grid[i][j:j+3]+   #top row of submatrix
                    grid[i+1][j:j+3]+ #middle row of the submatrix
                    grid[i+2][j:j+3]  #bottom row of the submatrix
                )

                #append the max_val to the current row of the res matrix
                res[i].append(max_val)
                
        #return resulting matrix
        return res
