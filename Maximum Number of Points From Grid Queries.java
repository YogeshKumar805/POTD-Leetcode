import java.util.*;

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length, n = grid[0].length;
        int k = queries.length;
        int[] result = new int[k];
        int[][] directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // Sort queries and store original indices
        int[][] sortedQueries = new int[k][2];
        for (int i = 0; i < k; i++) {
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }
        Arrays.sort(sortedQueries, Comparator.comparingInt(a -> a[0]));
        
        // Min heap (priority queue) storing (value, row, col)
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{grid[0][0], 0, 0});
        
        // Visited set
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        
        int count = 0; // Number of cells we can reach
        int prevQuery = 0; // Previous processed query
        
        for (int[] query : sortedQueries) {
            int qVal = query[0];
            int qIndex = query[1];
            
            // Process all cells whose value is < qVal
            while (!pq.isEmpty() && pq.peek()[0] < qVal) {
                int[] curr = pq.poll();
                int r = curr[1], c = curr[2];

                count++; // This cell contributes to the answer
                
                // Explore neighbors
                for (int[] dir : directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        pq.offer(new int[]{grid[nr][nc], nr, nc});
                    }
                }
            }
            
            result[qIndex] = count; // Store result for this query
        }
        
        return result;
    }
}
