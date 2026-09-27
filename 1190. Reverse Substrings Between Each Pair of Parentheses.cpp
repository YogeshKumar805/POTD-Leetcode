class Solution {
public:
    string reverseParentheses(auto& s) {
        int n = s.size();
        vector<int> link(n), stk;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.push_back(i);
            else if (s[i] == ')') {
                link[i] = stk.back();
                link[link[i]] = i;
                stk.pop_back();
            }
        }

        string res;
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] >= 'a')
                res += s[i];
            else {
                i = link[i];
                dir = -dir;
            }
        }

        return res;
    }
};
