int tens[6]={1, 10, 100, 1000, 10000, 100000};
class Solution {
public:
    vector<int> ans;
    inline void add2Ans(int x){
        int d=upper_bound(tens, tens+6, x)-tens-1;
        for(int i=d; i>=0; i--){
            auto [q, r]=div(x, tens[i]);
            ans.push_back(q);
            x=r;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        const int n=nums.size();
        ans.reserve(n*6);
        for(int x: nums) add2Ans(x);
        return ans;
    }
};
