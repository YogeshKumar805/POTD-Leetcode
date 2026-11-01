class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * ranges::min(nums));
    }
};
