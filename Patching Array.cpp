class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum=0;
        long long patches=0;
        long long i=0;

        while(sum<n){
            if(i<nums.size() && nums[i]<=sum+1){
                sum+=nums[i++];
            }else{
                patches++;
                sum+=sum+1;
            }
        }
        return patches;
    }
};
