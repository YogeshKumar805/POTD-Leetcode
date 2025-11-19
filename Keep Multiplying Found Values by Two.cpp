class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unsigned seen=0;
        for(int x: nums){
            auto [q, r]=div(x, original);
            if (r==0 && popcount((unsigned)q)==1){
                seen|=q; 
            }
        }
    //    cout<<seen<<endl;
        return original*(1<<countr_one(seen));
    }
};
