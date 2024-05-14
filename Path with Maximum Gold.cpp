class Solution {
public:
  int getMaximumGold(vector<vector<int>>& grid) {
      
   




        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        
        function<void(int,int,int)> dfsBacktrack = [&](int i, int j, int currentGold) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                return;
            }
            
            int goldInCurrentCell = grid[i][j];
            currentGold += goldInCurrentCell;
            maxGold = max(maxGold, currentGold);
            
            int temp = grid[i][j];
            grid[i][j] = 0;
            
            dfsBacktrack(i + 1, j, currentGold);
            dfsBacktrack(i - 1, j, currentGold);
            dfsBacktrack(i, j + 1, currentGold);
            dfsBacktrack(i, j - 1, currentGold);
            
            grid[i][j] = temp;
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    dfsBacktrack(i, j, 0);
                }
            }
        }
        
        return maxGold;
    }
};
