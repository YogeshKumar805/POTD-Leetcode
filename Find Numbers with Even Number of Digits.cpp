class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt =0;
        for(auto &x:nums) cnt +=  (((int)log10(x)+1)&1)^1;
        return cnt;
    }
};
