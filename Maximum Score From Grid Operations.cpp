using ll=long long;
static ll colSum[100][101]={{0}}; // 1-indexed prefix col sums
// (j, num of black items in curr col, cur col score exclusive/inclusive)
static ll dp[100][101][2];
static int n;

class Solution {
public:
    static long long maximumScore(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==1) return 0;
        // compute col prefix sums
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                colSum[j][i+1]=colSum[j][i]+grid[i][j];
            }
        }
        for(int j=0; j<n; j++)
            memset(dp[j], 0, sizeof(ll)*(n+1)*2);

        for(int j=1; j<n; j++){
            for(int b0=0; b0<=n; b0++){
                ll p0=dp[j-1][b0][0];
                ll p1=dp[j-1][b0][1];

                for(int b1=0; b1<=n; b1++){
                    bool isBigger=b1>b0;
                    
                    ll prvX=isBigger?(colSum[j-1][b1]-colSum[j-1][b0]):0;
                    ll curX=!isBigger?(colSum[j][b0]-colSum[j][b1]):0;
                    
                    // State 0: score in cur col exclusive
                    dp[j][b1][0]=max(dp[j][b1][0], max(prvX+p0, p1));
                    
                    // State 1: score in cur col inclusive
                    dp[j][b1][1]=max(dp[j][b1][1], curX+max(p1, prvX+p0));
                }
            }
        }
        ll ans=0;
        for(int b=0; b<=n; b++) 
            ans=max(ans, dp[n-1][b][1]);
        
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
