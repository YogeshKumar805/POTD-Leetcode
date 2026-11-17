class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size(), inf = INT_MAX / 2;
        auto peel = [&](int i, int j, int d) {  // s[i:j] in blocks of d: the outer pair of blocks, then the inside
            int changes = 0;
            for (; j - i > d; i += d, j -= d)
                for (int t = 0; t < d; ++t)
                    changes += s[i + t] != s[j - d + t];
            return changes;
        };

        vector cost(n + 1, vector(n + 1, inf));  // cost[i][j]: changes to make s[i:j] a semi-palindrome
        for (int d = 1; 2 * d <= n; ++d)
            for (int length = 2 * d; length <= n; length += d)  // every length that d divides, with d < length
                for (int i = 0, j = length; j <= n; ++i, ++j)
                    cost[i][j] = min(cost[i][j], peel(i, j, d));

        vector best(n + 1, inf);  // best[j]: the fewest changes for s[:j] cut into the pieces placed so far
        best[0] = 0;
        auto extend = [&](int j) {  // the newest piece s[i:j] starts at an old cut i and gets at least 2 letters
            return ranges::min(views::iota(0, j - 1) | views::transform([&](int i) { return best[i] + cost[i][j]; }));
        };
        for (int pieces = 1; pieces < k; ++pieces) {  // every piece but the last
            vector next(n + 1, inf);
            for (int j = 2 * pieces; j <= n - 2 * (k - pieces); ++j)  // 2 letters for each piece, placed or still to come
                next[j] = extend(j);
            swap(best, next);
        }
        return extend(n);  // the last piece ends at n
    }
};
