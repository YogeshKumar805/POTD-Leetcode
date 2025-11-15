uint16_t p0[40001];
int front, back;
class Solution {
public:
    static int numberOfSubstrings(string& s) {
        const int n=s.size();
        const int Zmax=(sqrt(1.0+4*n)-1)/2;
        front=back=0;// reset the queue p0
       
        for (int i=0; i<n; i++) {
            if (s[i]=='0') 
                p0[back++]=i;
        }
        p0[back++]=n;// add a sentinel at n
        int ans=0;

        for (int l=0; l<n; l++) {
            while(p0[front]<l) front++;
            int prev=l;
            for (int p=front; p<back; p++) {
                // this segment [l, r) has cnt0 0s
                int cnt0=p-front, r=p0[p];
                if (cnt0>Zmax) break;
                // dominant has min len cnt0*(cnt0+1)
                int minLen=max(prev-l+1, cnt0*(cnt0+1));
                // consider the dominant subarrays s[l..t]
                //  with  cnt0 0s & t<r 
                ans+=max(0, (r-l)-minLen+1);
                prev=r;
            }
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

