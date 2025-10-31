class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const int n=nums.size()-2;
        unsigned z=nums[n]^nums[n+1];
        for (int i=0; i<n; i++)
            z^=i^nums[i];

        int b=31-countl_zero(z);

        vector<int> ans(2, 0);
        for (int i=0; i<n; i++) {
            ans[(i>>b)&1]^=i;
            ans[(nums[i]>>b)&1]^=nums[i];
        }
        ans[(nums[n]>>b)&1]^=nums[n];
        ans[(nums[n+1]>>b)&1]^=nums[n+1];

        return ans;
    }
};
