class Solution {
    public boolean check(int[] nums) {
        int n=nums.length;
        int cnt=0;

        // Iterate through each possible rotation of the array
        for(int i=0; i<n; i++){
            // Reset the counter for each rotation
            cnt=0;

            // Check if the array is non-decreasing from index i
            for(int j=i+1; j<i+n; j++){
                // Compare the current element with the previous element in the rotated array
                if(nums[(j-1)%n]<=nums[j%n]){
                    cnt++; // Increment the counter if the order is maintained
                }
                else{
                    break; // Break the loop if the order is not maintained                    
                }
            }

            // If the array is non-decreasing for the entire rotation, return true            
            if(cnt+1==n){
                return true;
            }
        }

        return false;
    }
}
