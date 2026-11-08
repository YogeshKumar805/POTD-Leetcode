class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> rows(m), cols(n);  // servers on each row and column
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] && rows[i] + cols[j] > 2)  // it's counted in both, so more than 2 means company
                    ++ans;
        return ans;
    }
};
