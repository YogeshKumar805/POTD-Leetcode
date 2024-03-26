class Solution {
public:
    // time/space: O(n)/O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // discard the non-positive integers
        for (auto& num : nums) {
            if (num <= 0) num = n + 1;
        }

        // mark the visited integers as negative
        for (auto& num : nums) {
            int index = abs(num) - 1;
            if (index < n) nums[index] = -abs(nums[index]);
        }

        // find the smallest unvisited positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return (i + 1);
        }
        return (n + 1);
    }
};
