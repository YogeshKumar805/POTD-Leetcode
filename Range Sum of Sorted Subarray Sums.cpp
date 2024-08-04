class Solution {
public:
    static int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod=1e9+7;
        vector<int> sum;
        sum.reserve(n*(n+1)/2);
        for(int i=0; i<n; i++){
            int x=0;
            for(int j=i; j<n; j++){
                x+=nums[j];
                sum.push_back(x);
            }
        }
        sort(sum.begin(), sum.end());
        long long sumsum=accumulate(sum.begin()+left-1, sum.begin()+right, 0LL)%mod;

        return sumsum;
    }
};
