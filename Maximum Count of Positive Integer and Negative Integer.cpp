class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0, neg=0;
        for(int x:nums){
            pos+=x>0;
            neg+=x<0;
        }
        return max(pos, neg);
    }
};
