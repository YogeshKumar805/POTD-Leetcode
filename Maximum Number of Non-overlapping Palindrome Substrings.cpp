class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;

        int res = 0;

        for (int i = 0; i <= n - k;) {
            int step = 1;

            for (int d : {k, k + 1}) {
                if (i + d <= n && equal(s.begin() + i, s.begin() + i + (d >> 1),
                                        s.rbegin() + (n - (i + d)))) {
                    step = d;
                    res++;
                    break;
                }
            }

            i += step;
        }

        return res;
    }
};
