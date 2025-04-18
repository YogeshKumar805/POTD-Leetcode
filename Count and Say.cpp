class Solution {
public:
    using info = pair<int, char>;  // (frequency, digit)
    string str(const vector<info>& fc) {
        string ans;
        for (auto& [f, c] : fc) {
            ans+=to_string(f);
            ans.push_back(c);
        }
        return ans;
    }

    vector<info> freq(int n) {
        if (n==2) return {{1, '1'}};// base case
        auto fc=freq(n-1);// recursive call

        string s1=str(fc);

        int sz=s1.size();
        char c=s1[0];
        vector<info> ans={{1, c}};
        for (int i=1; i<sz; i++) {
            if (s1[i]==c) ans.back().first++;
            else {
                ans.emplace_back(1, s1[i]);
                c=s1[i];
            }
        }
        return ans;
    }

    string countAndSay(int n) {
        if (n==1) return "1";
        auto fc=freq(n);
        return str(fc);
    }
};
