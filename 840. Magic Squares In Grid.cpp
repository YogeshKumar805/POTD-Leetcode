class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        unordered_set<long long> magic = {
            0x276951438LL, 0x294753618LL, 0x438951276LL, 0x492357816LL,
            0x618753294LL, 0x672159834LL, 0x816357492LL, 0x834159672LL
        };
        
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                // center must be 5
                if (grid[i+1][j+1] != 5) continue;
                
                // encoding
                long long code = 0;
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        code = (code << 4) | grid[i+r][j+c];
                    }
                }
                
                if (magic.count(code)) count++;
            }
        }
        return count;
    }
};
