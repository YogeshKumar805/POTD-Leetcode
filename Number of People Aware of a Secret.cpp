class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9+7;

        vector<int> people;                 
        vector<pair<int,int>> status; //{can share, forget info}       
        int start = 0;                 

        people.push_back(1);
        status.push_back({1 + delay, 1 + forget - 1});

        for (int day = 2; day <= n; ++day) {
            while (start < status.size() && status[start].second < day) {
                start++;
            }

            int count = 0;
            for (int j = start; j < people.size(); j++) {
                int s = status[j].first; // start sharing info
                int f = status[j].second; // stop sharing info
                if (s <= day && day <= f) {
                    count = (count + people[j]) % MOD;
                }
            }

            if (count > 0) {
                people.push_back(count);
                status.push_back({day + delay, day + forget - 1});
            }
        }

        long long ans = 0;
        for (int j = start; j < people.size(); j++) {
            ans = (ans + people[j]) % MOD;
        }
        return ans;
    }
};
