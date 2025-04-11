class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0; // 🍥 Count of symmetric integers (chakra-balanced)

        for (int num = low; num <= high; ++num) {
            string str = to_string(num); // 🎭 Convert number to string form
            int len = str.length();

            // 🚫 Skip numbers with odd digits (can't balance chakra evenly)
            if (len % 2 != 0) continue;

            int half = len / 2;
            int leftSum = 0, rightSum = 0;

            // ⬅️ Calculate chakra in the left half
            for (int i = 0; i < half; ++i) {
                leftSum += str[i] - '0'; // Convert char to int
            }

            // ➡️ Calculate chakra in the right half
            for (int i = half; i < len; ++i) {
                rightSum += str[i] - '0';
            }

            // ☯️ If both halves have equal chakra, count it
            if (leftSum == rightSum) {
                count++;
            }
        }

        return count; // 🎯 Return total balanced numbers
    }
};
