import java.util.*;

class Solution {
    public int findRotateSteps(String ring, String key) {
        char[] r = ring.toCharArray();
        List<Integer>[] positions = new List[26];
        
        // Store the positions of each character in the ring
        for (int i = 0; i < r.length; i++) {
            int c = r[i] - 'a';
            if (positions[c] == null) positions[c] = new ArrayList<>();
            positions[c].add(i);
        }
        
        // Dynamic programming memoization
        int[][] dp = new int[key.length()][r.length];
        
        // Start with the first character of the key at position 0
        return helper(0, 0, positions, key.toCharArray(), r, dp);
    }
    
    // Recursive function with memoization
    int helper(int index, int pos, List<Integer>[] positions, char[] key, char[] ring, int[][] dp) {
        // If all characters of the key have been matched, return 0
        if (index == key.length) return 0;
        
        // If this state has already been computed, return the cached result
        if (dp[index][pos] > 0) return dp[index][pos];
        
        // Current character in the key
        char target = key[index];
        
        // List of possible positions of the current character in the ring
        List<Integer> possiblePositions = positions[target - 'a'];
        
        // Minimum steps required to reach the current character from the current position
        int minSteps = Integer.MAX_VALUE;
        
        // Iterate through possible positions and calculate minimum steps
        for (int nextPos : possiblePositions) {
            // Calculate the steps to move from the current position to the next position
            int steps = Math.min(Math.abs(nextPos - pos), ring.length - Math.abs(nextPos - pos));
            
            // Calculate steps for remaining characters recursively
            int totalSteps = steps + helper(index + 1, nextPos, positions, key, ring, dp);
            
            // Update the minimum steps
            minSteps = Math.min(minSteps, totalSteps);
        }
        
        // Cache the result and return
        return dp[index][pos] = minSteps + 1;
    }
}
