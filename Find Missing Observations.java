class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        
 int m = rolls.length;
        int totalSum = mean * (n + m);
        int observedSum = 0;
        
        for (int roll : rolls) {
            observedSum += roll;
        }
        
        int missingSum = totalSum - observedSum;
        
        // Check if it's possible to distribute missingSum across n rolls
        if (missingSum < n || missingSum > 6 * n) {
            return new int[0];  // return empty array
        }
        
        // Distribute missingSum across n rolls
        int quotient = missingSum / n;
        int remainder = missingSum % n;
        
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = quotient;
        }
        
        // Distribute the remainder
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }
        
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();}}
