class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0;
        long sum2 = 0;

        long zero1 = 0;
        long zero2 = 0;

        for (int num : nums1) {
            sum1 += num;
            if (num == 0) {
                zero1++;
                sum1 += 1; // Add 1 to simulate minimum positive value
            }
        }

        for (int num : nums2) {
            sum2 += num;
            if (num == 0) {
                zero2++;
                sum2 += 1; // Add 1 to simulate minimum positive value
            }
        }

        if ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
            return -1;
        }

        return Math.max(sum1, sum2);
    }
}
