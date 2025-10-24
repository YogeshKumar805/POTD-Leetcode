class Solution {
public:
    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> cnt(10, 0);
        for (char c : s) cnt[c - '0']++;
        for (int d = 0; d <= 9; d++) {
            if (cnt[d] && cnt[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; i++) {
            if (isBalanced(i)) return i;
        }
    }
};
