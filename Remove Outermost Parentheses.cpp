class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int lvl = 0;
        
        for (auto& c : s)
            if ((c == '(' && lvl++) || (c == ')' && --lvl))
                res += c;

        return res;
    }
};
