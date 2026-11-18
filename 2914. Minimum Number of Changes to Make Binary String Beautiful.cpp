class Solution {
public:
    int minChanges(string s) {
        return ranges::count_if(s | views::chunk(2), [](auto pair) { return pair[0] != pair[1]; });
    }
};
