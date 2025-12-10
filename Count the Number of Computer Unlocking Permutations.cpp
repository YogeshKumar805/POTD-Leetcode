class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1000000007;
        long long fact = 1;
        for(int i = 1; i < complexity.size(); i ++){
            if(complexity[i] <= complexity[0]){
                return 0;
            }
            fact *= i;
            fact %= mod;
        }
        return fact;
    }
};
