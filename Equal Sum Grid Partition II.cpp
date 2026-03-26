class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        unordered_map<long long,int> bottomMap,topMap, leftMap, rightMap;

        // Initialize bottomMap and rightMap
        for (auto &row : grid) {
            for (int x : row) {
                total += x;
                bottomMap[x]++;
                rightMap[x]++;
            }
        }

        long long sumTop = 0;

        // Horizontal cuts
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                sumTop += val;

                topMap[val]++;
                bottomMap[val]--;
            }

            long long sumBottom = total - sumTop;

            if (sumTop == sumBottom) return true;

            long long diff = abs(sumTop - sumBottom);

            if (sumTop > sumBottom) {
                if (check(topMap, grid, 0, i, 0, n-1, diff)) return true;
            } else {
                if (check(bottomMap, grid, i+1, m-1, 0, n-1, diff)) return true;
            }
        }

        long long sumLeft = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                sumLeft += val;

                leftMap[val]++;
                rightMap[val]--;
            }

            long long sumRight = total - sumLeft;
            if (sumLeft == sumRight) return true;

            long long diff = abs(sumLeft - sumRight);

            if (sumLeft > sumRight) {
                if (check(leftMap, grid, 0, m-1, 0, j, diff)) return true;
            } else {
                if (check(rightMap, grid, 0, m-1, j+1, n-1, diff)) return true;
            }
        }

        return false;
    }

    bool check(unordered_map<long long,int>& mp, vector<vector<int>>& grid,
           int r1, int r2, int c1, int c2, long long diff) {

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        // single cell
        if (rows * cols == 1) return false;

        // 1D row
        if (rows == 1) {
            return (grid[r1][c1] == diff || grid[r1][c2] == diff);
        }

        // 1D column
        if (cols == 1) {
            return (grid[r1][c1] == diff || grid[r2][c1] == diff);
        }

        return mp[diff]>0;
    }
};
