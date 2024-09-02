class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = accumulate(begin(chalk),end(chalk),0LL);
        k %= total;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k){
                return i;
            }else{
                k-=chalk[i];
            }
        }
        return -1;
    }
};
