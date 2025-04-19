class Solution {
    // 0 1 4 4 5 7
    //1 2 5 7 9
    int upper(int[] nums,int st,int end,int q){
        int ans = -1;
        while(st <=end){
            int mid = (st+end)>>1;
            if(nums[mid] <= q){
                ans = mid;
                st = mid+1;
            }
            else end = mid-1;
        } 
        return ans;
    }
     int lower(int[] nums ,int st,int end, int q){

        int ans = -1;
        while(st <=end){
            int mid = (st+end)>>1;
            if(nums[mid] >= q){
                ans = mid;
                end = mid-1;
            }
            else st = mid+1;
        } 
        return ans;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        long ans=0;
        int j = nums.length-1;
        Arrays.sort(nums);
        int u = nums.length-1;
        for(int i=0;i<u;i++){
            u = upper(nums,i+1,u,upper-nums[i]);
            int l = lower(nums,i+1,u,lower-nums[i]);
            if(u != -1 && l != -1) ans += u-l+1;
        }
        return ans;
    }
}
