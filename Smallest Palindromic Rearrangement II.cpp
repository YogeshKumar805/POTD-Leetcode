class Solution {
public:
    const long long LIMIT = 1000000;

    long long combCapped(long long n, long long r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        if (r == 0) return 1;

        __int128 res = 1;
        for (long long i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIMIT) return LIMIT + 1; 
        }
        return (long long)res;
    }

    long long countWays(vector<int>& cnt) {
        long long remaining = 0;
        for (int x : cnt) remaining += x;

        long long ans = 1;
        for (int c : cnt) {
            if (c == 0) continue;
            long long part = combCapped(remaining, c);
            ans *= part;
            if (ans > LIMIT) return LIMIT + 1;
            remaining -= c;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        char mid = 0;
        vector<int> half(26);
        int len = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] % 2) mid = char('a' + i);
        }

        if (countWays(half) < k) return "";

        string left = "";
        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left += char('a' + ch);
                    break;
                }
                k -= ways;
                half[ch]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + mid + right;
        return left + right;
    }
};
