class Solution {
    public void bfs(int[][] heights, Queue<int[]> queue, boolean[][] visited){
        int rows= heights.length;
        int cols= heights[0].length;
        int[][] directions= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!queue.isEmpty()){
            int[] cur= queue.poll();
            int cur_row= cur[0], cur_col= cur[1];
            for(int[] dir: directions){
                int next_row= cur_row+dir[0];
                int next_col= cur_col+dir[1];
                boolean cond1= next_row<0 || next_row>=rows || next_col<0 || next_col>=cols;
                boolean cond2= !cond1 && visited[next_row][next_col];
                boolean cond3= !cond1 && heights[next_row][next_col]< heights[cur_row][cur_col];
                if(cond1 || cond2 || cond3) continue;
                visited[next_row][next_col]= true;
                queue.add(new int[]{next_row, next_col});
            }
        }
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int rows= heights.length;
        int cols= heights[0].length;

        boolean[][] visited_atl= new boolean[rows][cols];
        boolean[][] visited_pac= new boolean[rows][cols];

        Queue<int[]> atl_queue= new LinkedList<>();
        Queue<int[]> pac_queue= new LinkedList<>();

        for(int r=0; r<rows; r++){
            pac_queue.add(new int[]{r, 0});
            atl_queue.add(new int[]{r, cols-1});
            visited_pac[r][0]= true;
            visited_atl[r][cols-1]= true;
        }

        for(int c=0; c< cols; c++){
            pac_queue.add(new int[]{0, c});
            atl_queue.add(new int[]{rows-1, c});
            visited_pac[0][c]= true;
            visited_atl[rows-1][c]= true;
        }

        bfs(heights, pac_queue, visited_pac);
        bfs(heights, atl_queue, visited_atl);

        List<List<Integer>> result= new ArrayList<>();
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(visited_pac[r][c] && visited_atl[r][c]){
                    result.add(Arrays.asList(r, c));
                }
            }
        }
        return result;
    }
}
