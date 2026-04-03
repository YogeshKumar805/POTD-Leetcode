class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& d, vector<int>& walls) {
        int n = robots.size();

        // Store robots as {position, distance}
        vector<array<int, 2>> x(n);
        for (int i = 0; i < n; i++) {
            x[i] = {robots[i], d[i]};
        }

        // Sort robots and walls to get everything in order
        sort(x.begin(), x.end());
        sort(walls.begin(), walls.end());

        // Dummy robot to avoid boundary checks
        x.push_back({(int)1e9, 0});

        // Function to count walls in range [l, r]
        auto query = [&](int l, int r) -> int {
            if (l > r) return 0;
            auto it1 = upper_bound(walls.begin(), walls.end(), r);
            auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return it1 - it2;
        };

        // dp[i][0] = i-th robot shoots LEFT
        // dp[i][1] = i-th robot shoots RIGHT
        vector<array<int, 2>> dp(n);

        // Base case (i = 0)- shooting left
        dp[0][0] = query(x[0][0] - x[0][1], x[0][0]);

        //shooting right
        if (n > 1) { 
            dp[0][1] = query(
                x[0][0],
                min(x[1][0] - 1, x[0][0] + x[0][1])
            );
        } else {
            dp[0][1] = query(x[0][0], x[0][0] + x[0][1]);
        }

        // DP transitions
        for (int i = 1; i < n; i++) {

            // Case 1: shoot RIGHT
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                       query(
                           x[i][0],
                           min(x[i + 1][0] - 1, x[i][0] + x[i][1])
                       );

            // Case 2: shoot LEFT (no overlap with previous LEFT)
            dp[i][0] = dp[i - 1][0] +
                       query(
                           max(x[i][0] - x[i][1], x[i - 1][0] + 1),
                           x[i][0]
                       );

            // Case 3: shoot LEFT but previous was RIGHT (handle overlap)
            int leftStart = max(x[i][0] - x[i][1], x[i - 1][0] + 1);
            int leftEnd   = x[i][0];

            int overlapStart = leftStart;
            int overlapEnd   = min(x[i - 1][0] + x[i - 1][1], x[i][0] - 1);

            int res = dp[i - 1][1]
                      + query(leftStart, leftEnd)
                      - query(overlapStart, overlapEnd);

            dp[i][0] = max(dp[i][0], res);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
