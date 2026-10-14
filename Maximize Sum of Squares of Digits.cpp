class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Step 1: the biggest possible digit sum is 9 * num
        if (sum > 9 * num) return "";

        string ans;

        // Step 2: fill every position from left to right
        while (num-- > 0) {
            int digit = min(9, sum);   // take as much as we can, at most 9
            ans += char('0' + digit);
            sum -= digit;
        }

        return sum == 0 ? ans : "";
    }
};
