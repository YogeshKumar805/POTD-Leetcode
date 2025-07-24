class Solution {
public:
    int ans=1e9,xo=0,time=0;
    void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& nums, vector<int>& sub, vector<int>& in, vector<int>& out)
    {
        in[node]=time++;
        sub[node]=nums[node];
        for(auto child: adj[node])
        {
            if(child==par) continue;
            dfs(child,node,adj,nums,sub,in,out);
            sub[node]^=sub[child];
        }
        out[node]=time++;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges)
    {
        int n=nums.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            xo^=nums[i];
        }
        for(int i=0;i<n-1;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> sub(n,0),in(n),out(n);
        dfs(0,0,adj,nums,sub,in,out);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i==j) continue;
                else if(in[i]<in[j] && out[i]>out[j])
                {
                    int x=sub[j];
                    int y=sub[i]^sub[j];
                    int z=xo^sub[i];
                    int mn=min(x,min(y,z)),mx=max(x,max(y,z));
                    ans=min(ans,mx-mn);
                }
                else if(in[i]>in[j] && out[i]<out[j])
                {
                    int x=sub[i];
                    int y=sub[i]^sub[j];
                    int z=xo^sub[j];
                    int mn=min(x,min(y,z)),mx=max(x,max(y,z));
                    ans=min(ans,mx-mn);
                }
                else 
                {
                    int x=sub[i];
                    int y=sub[j];
                    int z=xo^sub[i]^sub[j];
                    int mn=min(x,min(y,z)),mx=max(x,max(y,z));
                    ans=min(ans,mx-mn);
                }
            }
        }
        return ans;
    }
};
