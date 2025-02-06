class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> productCount = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount.put(product, productCount.getOrDefault(product, 0) + 1);
            }
        }
        int result = 0;
        for (int count : productCount.values()) {
            if (count > 1) {
                result += count * (count - 1) * 4; 
            }
        }
        return result;
    }
}
