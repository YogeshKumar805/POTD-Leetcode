int A[11];// only 11 possiblities
class Solution {
public:
    static void buildA(){
        if (A[0]==1) return; // only once
        A[0]=1;
        for(int i=1; i<=10; i++)
            A[i]=(1<<i)-1;// 2^i-1
    }
    static int smallestNumber(int n) {
        buildA();
        return *lower_bound(A, A+11, n);
    }
};
