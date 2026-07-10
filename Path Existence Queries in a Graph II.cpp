class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {nums[i], i};

        sort(a.begin(), a.end());

        vector<int> pos(n);
        vector<int> val(n);

        for (int i = 0; i < n; i++) {
            val[i] = a[i].first;
            pos[a[i].second] = i;
        }

        vector<int> R(n), L(n);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && val[j + 1] - val[i] <= maxDiff)
                ++j;
            R[i] = j;
            if (j < i) j = i;
        }

        j = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j - 1 >= 0 && val[i] - val[j - 1] <= maxDiff)
                --j;
            L[i] = j;
            if (j > i) j = i;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<vector<int>> upR(LOG, vector<int>(n));
        vector<vector<int>> upL(LOG, vector<int>(n));

        upR[0] = R;
        upL[0] = L;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                upR[k][i] = upR[k - 1][upR[k - 1][i]];
                upL[k][i] = upL[k - 1][upL[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (u < v) {

                if (R[u] == u) {
                    ans.push_back(-1);
                    continue;
                }

                int cur = u;
                int step = 0;

                for (int k = LOG - 1; k >= 0; k--) {
                    if (upR[k][cur] < v) {
                        cur = upR[k][cur];
                        step += 1 << k;
                    }
                }

                if (R[cur] < v)
                    ans.push_back(-1);
                else
                    ans.push_back(step + 1);

            } else {

                if (L[u] == u) {
                    ans.push_back(-1);
                    continue;
                }

                int cur = u;
                int step = 0;

                for (int k = LOG - 1; k >= 0; k--) {
                    if (upL[k][cur] > v) {
                        cur = upL[k][cur];
                        step += 1 << k;
                    }
                }

                if (L[cur] > v)
                    ans.push_back(-1);
                else
                    ans.push_back(step + 1);
            }
        }

        return ans;
    }
};
