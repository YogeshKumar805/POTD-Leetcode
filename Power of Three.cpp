class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int count1 = 0;
        while (n > 0) {
            int digit = n % 3;
            if (digit == 1) {
                count1++;
                if (count1 > 1) return false;
            }
            if (digit == 2) return false;
            n /= 3;
        }
        return count1 == 1;
    }
};
