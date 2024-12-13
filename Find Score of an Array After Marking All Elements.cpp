class Solution {
public:
    long long findScore(vector<int>& nums) {
       vector<int>vis(nums.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        long long ans=0;
        while(pq.size())
        {
            int ind=pq.top().second;
            if(vis[ind])
            {
                pq.pop();
                continue;
            }
            ans+=pq.top().first;
            vis[ind]=1;
            if(ind-1>=0)
                vis[ind-1]=1;
            
            if(ind+1<nums.size())
                vis[ind+1]=1;
            
            pq.pop();
        }
        return ans;
    }
};
