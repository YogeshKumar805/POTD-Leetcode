class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int INC = 1;
        int INC_MAX = 1;
        int DEC = 1;
        int DEC_MAX = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                INC++;
            } else {
                INC_MAX = max(INC, INC_MAX);
                INC = 1;
            }
            if (nums[i] > nums[i + 1]) {
                DEC++;
            } else {
                DEC_MAX = max(DEC, DEC_MAX);
                DEC = 1;
            }
        }

        INC_MAX = max(INC, INC_MAX);
        DEC_MAX = max(DEC, DEC_MAX);
        return max(INC_MAX, DEC_MAX);
    }
};
