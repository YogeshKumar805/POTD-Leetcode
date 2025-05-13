
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;

    int lengthAfterTransformations(const string& s, int t) {
        vector<int> arr(26, 0);
        for (char c : s) {
            arr[c - 'a']++;
        }

        while (t-- > 0) {
            vector<int> temp(26, 0);
            for (int j = 0; j < 25; ++j) {
                temp[j + 1] = arr[j];
            }
            temp[0] = (temp[0] + arr[25]) % MOD;
            temp[1] = (temp[1] + arr[25]) % MOD;
            arr = move(temp);
        }

        int res = 0;
        for (int num : arr) {
            res = (res + num) % MOD;
        }

        return res;
    }
};
