class Solution {
public:
    static int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return (nums[0]-1)*(nums.back()-1);
        int m0=nums[0],m1=nums[1];
        if(m0<m1) swap(m0,m1);
        for (int i=2;i<n;i++){
            const int x=nums[i];
            bool ge0=x>m0, ge1=(!ge0) & (x>m1);
            m1+=(-(ge0) & m0-m1)+(-(ge1) & x-m1);
            m0+=(-(ge0) & x-m0);
        }
        return (m0-1)*(m1-1);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
