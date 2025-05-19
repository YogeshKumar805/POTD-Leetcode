class Solution {
public:
    string triangleType(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+1, nums.end());
        if (nums[2]>=nums[0]+nums[1]) return "none";
        if (nums[0]==nums[2]) return "equilateral";
        if (nums[0]==nums[1] || nums[1]==nums[2]) return "isosceles";
        return "scalene";
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
