class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(auto &c: s){

            mp[c]++;
            
        }

        bool flag = false;
        int cnt = 0;

        for(auto &i : mp){

            if(i.second % 2 == 0) cnt += i.second;
            else {
                cnt += i.second - 1;
                flag = true;
            }
            
        }

        return (flag) ? cnt + 1: cnt;
    }
};
