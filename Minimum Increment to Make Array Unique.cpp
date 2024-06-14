class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        const int m = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<m;++i){
            if(nums[i]<=nums[i-1]){int diff = nums[i-1]+1-nums[i];ans+=diff;nums[i]+=diff;}
        }
        return ans;
    }
};
