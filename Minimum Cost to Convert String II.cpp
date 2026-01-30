// Use DP+ Floyd Warshall's algorithm
uint64_t D[201][201];
uint64_t dp[1001];
class Solution {
public:
    unordered_map<string, int> id;
    unordered_set<int> lens;

    void init() {// fill all with ULLONG_MAX for all at 1 times
        if (D[0][0]==ULLONG_MAX) return;
        memset(D, 255, sizeof(D));
    }
    void FW(int m, int& sz, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int row, col;
        for (int i=0; i<m; i++) {
            string& s=original[i];
            string& t=changed[i];

            auto it=id.find(s);
            if (it==id.end()) {
                row=sz++;
                int slen=s.size();
                auto it_lens=lens.find(slen);
                if (it_lens==lens.end())
                    lens.insert(slen);
                id[s]=row;
            }
            else
                row=it->second;
            it=id.find(t);
            if (it==id.end()) {
                col=sz++;
                id[t]=col;
            }
            else
                col=it->second;
            D[row][col]=min(D[row][col], (uint64_t)cost[i]);
        }
        for (int i=0; i<sz; i++) D[i][i]=0;

        for (int k=0; k<sz; k++) {
            for (int i=0; i<sz; i++) {
                if (D[i][k]<ULLONG_MAX) {
                    for (int j=0; j<sz; j++) {
                        if (D[k][j]<LLONG_MAX) {
                            D[i][j]=min(D[i][j], D[i][k] + D[k][j]);
                        }
                    }
                }
            }
        }
    }

    long long minimumCost(string& source, string& target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        init();
        const int m=original.size(), n=source.size();       
        id.reserve(m*2);
        lens.reserve(n);
        int sz=0;
        FW(m, sz, original, changed, cost);
        
        memset(dp, 255, sizeof(uint64_t)*(n+1));
        dp[0]=0;
        for (int i=0; i<n; i++) {
            if (dp[i]==ULLONG_MAX) continue;
            if (source[i]==target[i])
                dp[i+1]=min(dp[i+1], dp[i]);

            for (int t : lens) {
                if (i+t>n) continue;

                string s_sub=source.substr(i, t);
                string t_sub=target.substr(i, t);
                auto it=id.find(s_sub);
                int x=(it!=id.end()) ? it->second : -1;
                it=id.find(t_sub);
                int y=(it!=id.end()) ? it->second : -1;

                if (x>=0 && y>=0 && D[x][y]<ULLONG_MAX) {
                    dp[i+t]=min(dp[i+t], dp[i]+D[x][y]);
                }
            }
        }
        for (int i=0; i<sz; i++)// reset for the next testcase
            memset(D[i], 255, sizeof(uint64_t)*sz);
        return dp[n]==ULLONG_MAX ? -1 : dp[n];
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
