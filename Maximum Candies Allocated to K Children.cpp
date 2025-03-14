class Solution {
public:
    bool get_c(vector<int>& candies, long long k, int c) {
        [[unroll]]
        for (int x : candies) {
            k-=x/c;
            if (k<=0) return 1;
        }
        return 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        const long long sum=accumulate(candies.begin(), candies.end(), 0LL);
        if (sum<k) return 0;

        int l=1, r=sum/k, m;  // sum/k as the upper bound
        while (l<r) {
            m=l+(r-l+1)/2;  // upper mid to avoid infinite loop
            if (get_c(candies, k, m)) l=m;
            else r=m-1;
        }
        return l;
    }
};
