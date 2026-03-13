//Approach 2(optimal)
class Solution {
public:
    typedef long long ll;
    bool solve(ll height,vector<int>&time,ll T){
        ll heightCanBeBreaken=0;
        for(auto ti:time){
           ll h=(-1+sqrt(1+(8*T)/ti))/2;
           heightCanBeBreaken+=h;
           if(heightCanBeBreaken>=height)return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low=0,high=1e18,ans=1e18;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(solve(1ll*mountainHeight,workerTimes,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
//Approach 1
class Solution {
public:
    typedef long long ll;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        //approach 1
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        // next_free_time base_time piles_eaten
        for(auto it:workerTimes){
            pq.push({it,it,1});
        }
        ll ans=0,currHeight=mountainHeight;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll maxTimeHeWorked=it[0];
            ll baseTime=it[1];
            ll reduced=it[2];
            ans=max(ans,maxTimeHeWorked);
            currHeight--;
            if(currHeight==0)break;
            ll nextheight=reduced+1;
            ll totalTimeToBreak=(baseTime*(nextheight)*(nextheight+1))/2;
            pq.push({totalTimeToBreak,baseTime,nextheight});
        }
        return ans;
    }
};
