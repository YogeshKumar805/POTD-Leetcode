class Solution {
public:
    static bool judgeCircle(string& moves) {
        return accumulate( moves.begin(), moves.end(), 0,
            [](int balanced, char c){ 
                return balanced+=(c=='R')-(c=='L')+(((c=='U')-(c=='D'))<<15);
            })==0;
    }
};
