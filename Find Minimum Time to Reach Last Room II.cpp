class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        dist[0][0][0] = 0;
        pq.emplace(0, 0, 0, 0);
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto [time, i, j, parity] = pq.top(); pq.pop();
            if (i == n - 1 && j == m - 1) return time;
            if (time > dist[i][j][parity]) continue;
            for (auto& dir : dirs) {
                int ni = i + dir.first, nj = j + dir.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int next_cost = (parity == 0) ? 1 : 2;
                    int wait_time = max(time, moveTime[ni][nj]);
                    int arrival = wait_time + next_cost;
                    int next_parity = 1 - parity;

                    if (arrival < dist[ni][nj][next_parity]) {
                        dist[ni][nj][next_parity] = arrival;
                        pq.emplace(arrival, ni, nj, next_parity);
                    }
                }
            }
        }
        return -1;
    }
};
