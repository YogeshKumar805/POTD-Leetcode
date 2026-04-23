class Solution {
public:
    static void print(auto& c){
        for (auto x: c)cout<<x<<", ";
        cout<<endl;
    }
    static vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> idx;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int x=nums[i];
            if (idx.count(x)==0) idx[x]={i};
            else idx[x].push_back(i);
        }
        vector<long long> ans(n, 0);
        for(auto& [x, v]: idx){
        //    cout<<"x="<<x<<":"; print(v);
            int vs=v.size();
            if (vs==1) continue;
            vector<long long> sum(vs+1);
            for(int i=0; i<vs; i++){
                sum[i+1]=sum[i]+v[i];
            }
        //    cout<<"sum"<<":"; print(sum);
            for(int i=0; i<vs; i++){
                ans[v[i]] = sum.back()-2LL*sum[i] - (vs-2LL*i) * v[i];

            }

        }
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
