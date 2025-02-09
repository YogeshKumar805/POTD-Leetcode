class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        int diff;
        unordered_map<int,int> counter;
        unsigned long long count=0;
        for(int i=0;i<n;i++){
            diff = nums[i]-i;
            count-=counter[diff];
            counter[diff]++;
            count += (n-i-1);
        }
        return count;
    }
};
