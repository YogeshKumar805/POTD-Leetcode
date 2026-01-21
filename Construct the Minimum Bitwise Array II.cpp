class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& p: nums) {
            int remB=((p+1)& ~p)>>1;
            p^=(remB)|(-(remB==0) & ~p);
        }
        return move(nums);
    }
};
