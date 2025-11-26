// variant with better initialization
class Solution {
public:
    static int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int m=grid.size(), n=grid[0].size();
        const int mod=1e9+7;
        int dp[2][n][k];
        memset(dp, 0, sizeof(dp));
        dp[0][0][(k-grid[0][0]%k)%k]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                const int x=grid[i][j];
                for(int r=0; r<k; r++){
                    const int R0=(r+x)%k;
                    if (i>0) dp[i&1][j][r]=dp[(i-1)&1][j][R0];
                    if (j>0) dp[i&1][j][r]+=dp[i&1][j-1][R0];
                    dp[i&1][j][r]%=mod;
                }
            }
        }
        return dp[(m-1)&1][n-1][0];
    }
};
