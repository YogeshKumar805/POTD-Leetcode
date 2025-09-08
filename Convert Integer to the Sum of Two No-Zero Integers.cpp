class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int n1 = 0,n2 = 0;
        int pos = 1;
        while(n){
            int num = n%10;
            if(num == 0){
                n1 += 1*pos;
                n2 += 9*pos;
                n -= 10;
            }else if(num == 1 && n>=10){
                n1 += 2*pos;
                n2 += 9*pos;
                n -= 10;
            }else{
                n1 += (num-1)*pos;
                n2 += 1*pos;
            }
            pos *= 10; n/=10;
        }
        return {n1,n2};
    }
};
