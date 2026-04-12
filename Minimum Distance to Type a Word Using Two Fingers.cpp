int dp[300][27];
class Solution {
public:
    static inline int dist(int x, int y) {
        if (x==26 || y==26) return 0; // 26 denotes hovering 
        return abs(x/6-y/6)+abs(x%6-y%6);
    }

    static int minimumDistance(string& word) {
        const int n=word.size();
        constexpr int INF=1e9+7;
        fill(&dp[0][0], &dp[0][0]+n*27, INF);// reset 
        dp[0][26]=0;
        int prev=word[0]-'A'; 

        for (int i=1; i<n; i++) {
            int x=word[i]-'A';

            for (int j=0; j<27; j++) {
                if (dp[i-1][j]>=INF) continue;

                // Move the current finger
                dp[i][j]=min(dp[i][j], dp[i-1][j] + dist(prev, x));

                // Move the other finger 
                dp[i][prev]=min(dp[i][prev], dp[i-1][j]+dist(j, x));
            }
            prev=x; // Update prev to x
        }

        return *min_element(dp[n-1], dp[n-1]+27);
    }
};
