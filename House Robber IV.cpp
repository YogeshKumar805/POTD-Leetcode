class Solution {
public:
    bool check(vector<int>& nums, int k ,int poss_ans){
        int house_count =0;
        int n = nums.size();
        int i = 0 ;
        while(i<n){
            if(nums[i]<=poss_ans){ //just check whether the possible answer is the max in atleast k houses 
            // since we have a possible ans we have to just check whether its possible or not 
                house_count++ ;
                i++;
            }
         if(house_count >= k) return true; // if its possible in between  return true
         i++;
        }
        return k<=house_count;
    }
    int minCapability(vector<int>& nums, int k) {
        int n =nums.size() ;
        int lo = *min_element(nums.begin(),nums.end());
        int hi = *max_element(nums.begin(),nums.end());
        int ans =0 ;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2 ;
            if(check(nums,k,mid)){
                ans = mid ;
                hi = mid-1; // if current mid is possible then try to reduce the ans 
            }
            else {
                lo = mid+1;
            }
        } 
    return ans;
    }
};
