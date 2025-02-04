class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], sum = nums[0];
        for(int i = 1; i < n; ++i) 
            ans = max(ans, sum += nums[i] > nums[i - 1] ? nums[i] : -sum + nums[i]);
        return ans;
    }
};
