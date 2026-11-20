class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        int best = 1, keep = 1, bump = 1, last = -10;
        for (int x : nums) {
            switch (x - last) {
                case 0: bump = keep + 1; break;  // x repeat: bump it on top of keep
                case 1: ++keep, ++bump; break;  // x extends keep, x + 1 extends bump
                case 2: keep = bump + 1, bump = 1; break;  // x extends bump, x + 1 starts over
                default: keep = bump = 1;
            }
            best = max({best, keep, bump}), last = x;
        }
        return best;
    }
};
