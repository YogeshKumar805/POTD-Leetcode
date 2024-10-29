class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        # Get the dimensions of the grid
        m, n = len(grid), len(grid[0])
        
        # Directions for possible moves: (row offset, col offset)
        directions = [(-1, 1), (0, 1), (1, 1)]
        
        # Memoization cache to store the max moves from each cell
        memo = {}
        
        # Helper function to perform DFS with memoization
        def dfs(row, col):
            # If we are at the last column, no further moves are possible
            if col == n - 1:
                return 0
            # If already computed, return the stored result
            if (row, col) in memo:
                return memo[(row, col)]
            
            max_moves = 0
            current_value = grid[row][col]
            
            # Check all possible moves
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                # Check if the move is valid
                if 0 <= new_row < m and 0 <= new_col < n and grid[new_row][new_col] > current_value:
                    # Calculate moves from the next cell
                    max_moves = max(max_moves, 1 + dfs(new_row, new_col))
            
            # Store the result in memo
            memo[(row, col)] = max_moves
            return max_moves
        
        # Try to start from each cell in the first column and find the max moves
        result = 0
        for i in range(m):
            result = max(result, dfs(i, 0))
        
        return result
