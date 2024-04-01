class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int n=s.length()-1;
        while(s[n--]==' ');
        while(n>=0&&s[n--]!=' ')ans++;
        return ans+1;
    }
};
