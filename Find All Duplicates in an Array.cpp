class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> M;
        vector<int> ans;
        
        for(auto it : nums)
        {
            M[it]++;
        }
        for(auto bt : M)
        {
            if(bt.second==2)
            {
                ans.push_back(bt.first);
            }
        }
        return ans;
    }
};
