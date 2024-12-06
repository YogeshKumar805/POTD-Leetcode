class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ans(banned.begin(),banned.end());//to check in O(1) complexity if range of number is in banned or not
        int count=0;  //For counting integers
        int sum=0;  //to check the sum exceed or not
        int i=1; //For the Range of number
        while(i<=n&&sum+i<=maxSum){
            if(ans.find(i)==ans.end()){
                cout<<i<<endl;
                count++;
                sum+=i;
            }
            i++;
        }
        return count;
    }
};
