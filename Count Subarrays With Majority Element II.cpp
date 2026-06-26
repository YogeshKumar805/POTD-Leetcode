// 1-based indexed segmented tree defined recursively
static constexpr int N=1<<19;// 2*bit_ceil(2e5+2)<=(1<<19)
using ll=long long;
int seg[N];// as global variable
struct segTree{
    unsigned n;
    segTree(unsigned n): n(n){
        int nn=2*bit_ceil(n+1U);
        memset(seg, 0, nn*sizeof(int));
    }
    void update(int idx, int l, int r, int pos) {
        if (l==r){
            seg[idx]++;
            return ;
        }
        else{
            const int m=(l+r)/2;
            if (pos<=m) 
                update(2*idx, l, m, pos);
            else 
                update(2*idx+1, m+1, r, pos);
            seg[idx]=seg[2*idx]+seg[2*idx+1];
        }
    }
    // range query
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr<l || r<ql) return 0;
        if (ql<=l && r<=qr) return seg[idx];
        const int m=(l+r)/2;
        return query(2*idx, l, m, ql, qr)+query(2*idx+1, m+1, r, ql, qr);
    }
};

class Solution {
public:
    static long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(), bias=n+1, maxV=bias<<1;
        segTree tree(maxV);
        long long ans=0, sum=0;
        tree.update(1,0, maxV, sum+bias);
        for (int x : nums) {
            sum+=((x==target)<<1)-1;
            ans+=tree.query(1, 0, maxV, 0, sum+bias-1);
            tree.update(1, 0, maxV, sum+bias);
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
