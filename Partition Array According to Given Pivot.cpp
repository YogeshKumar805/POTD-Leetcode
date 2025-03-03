class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        if (n==1) return nums;
        vector<int> ans, M, R;
        int l=0, m=0, r=0;
        ans.reserve(n);
        for(int x: nums){
            if (x<pivot) ans.push_back(x), l++;
            else if (x>pivot) R.push_back(x), r++;
            else M.push_back(x), m++;
        }
        auto it_m=ans.begin()+l;
        auto it_l=ans.begin()+(l+m);
        ans.insert(it_m, M.begin(), M.end());
        ans.insert(it_l, R.begin(), R.end());
        return ans;
    }
};
