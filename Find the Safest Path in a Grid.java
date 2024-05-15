class Solution {

    static int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        int[][] dist = new int[n][n];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        Queue<int[]> q = new LinkedList<>();

        // Initialize all thief positions
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid.get(r).get(c) == 1) {
                    q.offer(new int[]{r, c});
                    dist[r][c] = 0;
                }
            }
        }

        // Multi-source BFS to calculate minimum distance to any thief
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int r = cell[0], c = cell[1];
            for (int[] dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == Integer.MAX_VALUE) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.offer(new int[]{nr, nc});
                }
            }
        }

        // Use priority queue to find path with maximum safeness factor
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        pq.offer(new int[]{dist[0][0], 0, 0});
        int[][] maxSafeness = new int[n][n];
        for (int[] row : maxSafeness) Arrays.fill(row, -1);
        maxSafeness[0][0] = dist[0][0];

        while (!pq.isEmpty()) {
            int[] cell = pq.poll();
            int d = cell[0], r = cell[1], c = cell[2];
            if (r == n - 1 && c == n - 1) return d;

            for (int[] dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newSafe = Math.min(d, dist[nr][nc]);
                    if (newSafe > maxSafeness[nr][nc]) {
                        maxSafeness[nr][nc] = newSafe;
                        pq.offer(new int[]{newSafe, nr, nc});
                    }
                }
            }
        }

        return -1;  // In case there's no valid path        
    }
}
