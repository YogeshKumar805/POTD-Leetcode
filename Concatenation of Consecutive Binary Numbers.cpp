class Solution {
public:
    static int concatenatedBinary(int n) {
        constexpr int mod=1e9+7;
        uint64_t ans=0;
        for(unsigned x=1; x<=n; x++){
            const int bw=32-countl_zero(x);
            ans=(ans<<bw)+x;
            if (ans>=mod) ans%=mod;
        }
        return ans;
    }
};
