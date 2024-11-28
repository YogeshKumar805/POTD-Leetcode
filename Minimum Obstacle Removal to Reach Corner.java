class Solution {
    public int minimumObstacles(int[][] grid) {
        int m= grid.length, n= grid[0].length;
        int dp[][]= new int[m][n];
        for(int[] a: dp) Arrays.fill(a, Integer.MAX_VALUE);
        dp[0][0]=0;
        int[][] dir= new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        Deque<int[]> dq= new ArrayDeque<>();
        dq.addFirst(new int[]{0, 0});
        while(!dq.isEmpty()){
            int[] cur= dq.pollFirst();
            int x= cur[0], y=cur[1];
            for(int[] d: dir){
                int nx= x+d[0], ny= y+d[1];
                if(nx>=0 && ny>=0 && nx<m && ny <n){
                    int nc= dp[x][y]+grid[nx][ny];
                    if(nc<dp[nx][ny]){
                        dp[nx][ny]= nc;
                        if(grid[nx][ny]==0) dq.addFirst(new int[]{nx, ny});
                        else dq.addLast(new int[]{nx, ny});
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
}
