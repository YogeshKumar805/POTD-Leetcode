class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0] == b[0])
                    return a[1] - b[1];
                return a[0] - b[0];
            }    
        }); 
        for(int i=0; i<nums.length; i++)
            pq.add(new int[]{nums[i], i});
        
        for(int i=0;i<k;i++) {
            int[] val = pq.poll();
            nums[val[1]] *= multiplier;
            val[0] = nums[val[1]];
            pq.add(val);
        }
        return nums;
        
    }
}
