class Solution {
    static const int n = 1000005;
    static inline bitset<n> prime;
    static inline bool init = []() {
        prime.set(0);
        prime.set(1);
        for (int i = 2; i <= 1000; i++)
            if (!prime.test(i))
                for (int j = i * i; j < n; j += i)
                    prime.set(j);
        return true;
    }();

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int max = *max_element(nums.begin(), nums.end());

        vector<int> head(max + 1, -1);
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            next[i] = head[nums[i]];
            head[nums[i]] = i;
        }

        vector<int> dp(n, -1);
        dp[0] = 0;

        queue<int> queue;
        queue.push(0);

        unordered_set<int> seen;

        while (!queue.empty()) {
            int dq = queue.front();
            queue.pop();

            if (dq == n - 1)
                return dp[dq];

            int right = dq + 1;
            if (right < n && dp[right] == -1) {
                dp[right] = dp[dq] + 1;
                queue.push(right);
            }

            int left = dq - 1;
            if (left >= 0 && dp[left] == -1) {
                dp[left] = dp[dq] + 1;
                queue.push(left);
            }

            int val = nums[dq];
            if (!prime.test(val) && seen.find(val) == seen.end()) {
                seen.insert(val);
                for (int i = val; i <= max; i += val) {
                    for (int j = head[i]; j != -1; j = next[j]) {
                        if (dp[j] == -1) {
                            dp[j] = dp[dq] + 1;
                            queue.push(j);
                        }
                    }
                    head[i] = -1;
                }
            }
        }

        return -1;
    }
};
