class Solution {
public:
    int count = 0;
    int k;
    vector<vector<int>> adj;
    vector<int> values;

    long long dfs(int node, int parent) {
        long long sum = values[node];

        for (int child : adj[node]) {
            if (child == parent) continue;
            sum += dfs(child, node);
        }
        if (sum % k == 0) {
            count++;
            return 0; 
        }

        return sum; 
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        this->values = values;
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        return count;
    }
};
