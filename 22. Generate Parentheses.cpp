class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n-- == 1) return {"()"};

        vector<string> res;
        auto dfs = [&](auto& self, int O, int C, string s) -> void {
            if (O == 0 && C == 0) {
                res.push_back(s + ")");
                return;
            }

            if (O > 0)
                self(self, O - 1, C, s + "(");

            if (C >= O)
                self(self, O, C - 1, s + ")");
        };

        dfs(dfs, n, n, "(");

        return res;
    }
};
