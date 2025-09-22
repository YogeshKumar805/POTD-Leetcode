class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        int maxF = 0;
        int count = 0;
                for (int num : nums) {
            int f = freq.getOrDefault(num, 0) + 1;
            freq.put(num, f);
            
            if (f > maxF) {
                maxF = f;
                count = f; 
            } else if (f == maxF) {
                count += f; 
            }
        }
        
        return count;
    }
}
