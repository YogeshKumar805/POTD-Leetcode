class Solution {
public:
    bool checkValidString(string s) {
        int low = 0; // minimum number of open parenthesis
        int high = 0; // maximum number of open parenthesis

        for (char c : s) {
            low += (c == '(') ? 1 : -1;
            high += (c != ')') ? 1 : -1;

            if (high < 0) break; // We have more closing parenthesis than open
            low = max(low, 0); // We cannot have less than 0 open parenthesis
        }

        return low == 0; // Valid string if we can have exactly 0 open parenthesis
    }
};
