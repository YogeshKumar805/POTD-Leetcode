class Solution {
    public boolean divideArray(int[] nums) {
        int len = nums.length;
        int xor1=0, xor2=0;
        
        for(int i=0;i<len;i++){
            xor1 = nums[i]^xor1;
            xor2 = (nums[i]+1)^xor2;
        }

        return xor1==0 && xor2==0;
    }
}
