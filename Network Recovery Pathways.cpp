class Solution {
public:

    bool check(long long mid, vector<vector<pair<int, int>>> &adj, vector<int> &topo, vector<bool> &online, long long k, int n) {

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;

            // Intermediate offline nodes cannot be used
            if (u != 0 && u != n - 1 && !online[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (w < mid) continue;
                if (v != n - 1 && !online[v]) continue;

                dist[v] = min(dist[v], dist[u] + w);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);

        int mx = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
            mx = max(mx, w);
        }

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        long long low = 0, high = mx;
        int ans = -1;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (check(mid, adj, topo, online, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
