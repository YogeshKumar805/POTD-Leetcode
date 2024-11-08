class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n=nums.length;
        int[] ans=new int[n];
        int val=(int)Math.pow(2, maximumBit)-1;
        
        int k=n-1;
        int curr=0;
        for(int i=0; i<n; i++){
            curr ^=nums[i];
            ans[k--]=curr^val;            
        }
        
        return ans;
    }
}
