class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<int> server_rows(ROWS);
        vector<int> server_cols(COLS);

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1) {
                    server_rows[r]++;
                    server_cols[c]++;
                }
            }
        }
        int ans = 0;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1) {
                    if(server_rows[r] > 1 || server_cols[c] > 1) {
                        ans++;
                    }
                }
            }
        }

        return ans;

    }
};
