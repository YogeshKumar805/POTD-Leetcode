const int N=200000;
unsigned X[N], Y[N];// pair (x, isStart)-> (x<<1)+isSart
class Solution {
public:
    static bool cut3(unsigned* X, int M){
        sort(X, X+M);
        int sum=0, touch0=0;
        for(int i=0; i<M-1; i++){// last end not used
            sum+=(X[i]&1)*2-1;
            touch0+=sum==0;// sum==0 means that it can be cutted here
            if (touch0>=2) return 1;
        }
        return 0;
    }
    static bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const int m=rectangles.size(), M=m*2;
        int i=0;
        for(auto& r: rectangles){
            const unsigned xs=r[0], ys=r[1], xe=r[2], ye=r[3];
            X[i]=(xs<<1)+1; Y[i++]=(ys<<1)+1;//Encode xs,ys with LSB mark 1
            X[i]=(xe<<1)  ; Y[i++]=(ye<<1); // Encode xe,ye with LSB mark 0
        }
        return cut3(X, M) || cut3(Y, M);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
