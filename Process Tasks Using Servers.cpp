class Solution {
    struct Server {
        long long at;  // the second it frees up; 0 while free, so free servers sort by weight, then index
        int weight, index;
        auto operator<=>(const Server&) const = default;
    };
    using MinHeap = priority_queue<Server, vector<Server>, greater<>>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<Server> all;
        for (int i = 0; i < ssize(servers); ++i) all.push_back({0, servers[i], i});
        MinHeap free(greater<>{}, std::move(all));

        MinHeap busy;
        vector<int> ans;
        for (int s = 0; s < ssize(tasks); ++s) {
            while (!busy.empty() && busy.top().at <= s) {  // done by second s
                auto [at, weight, index] = busy.top();
                busy.pop();
                free.push({0, weight, index});
            }
            MinHeap& from = free.empty() ? busy : free;  // none free: the first to finish takes it
            auto [at, weight, index] = from.top();
            from.pop();
            busy.push({max<long long>(at, s) + tasks[s], weight, index});
            ans.push_back(index);
        }

        return ans;
    }
};
