class Solution {
public:
    int len;
    int toInt(string& nums){
        int x=0;
        for(char c: nums){
            x=(x<<1)+(c-'0');
        }
        return x;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        len=nums[0].size();
        vector<bool> hasX(1<<len, 0);

        for(auto& x:  nums)
            hasX[toInt(x)]=1;
        int N=0;//find N
        for(; N<(1<<len) && hasX[N]; N++);
    //    cout<<N<<endl;
        string ans=string(len, '0');
        for(int i=len-1; i>=0 && N>0; i--){
            ans[i]=(N&1)+'0';
            N>>=1;
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
