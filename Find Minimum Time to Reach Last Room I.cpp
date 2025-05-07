class Solution {
public:
    int minTimeToReach(vector<vector<int>>&a) {
        int n=a.size(),m=a[0].size();
        priority_queue<pair<int,pair<int,int>>>Q;
        Q.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        while(!Q.empty()){
            int newd=Q.top().first;
            int x=Q.top().second.first;
            int y=Q.top().second.second;
            Q.pop();
            if(y+1<m&&dist[x][y+1]>max(newd+1,a[x][y+1]+1)){
                Q.push({max(newd+1,a[x][y+1]+1),{x,y+1}});
                dist[x][y+1]=max(newd+1,a[x][y+1]+1);
            }
            if(x-1>=0&&dist[x-1][y]>max(newd+1,a[x-1][y]+1)){
                Q.push({max(newd+1,a[x-1][y]+1),{x-1,y}});
                dist[x-1][y]=max(newd+1,a[x-1][y]+1);
            }
            if(y-1>=0&&dist[x][y-1]>max(newd+1,a[x][y-1]+1)){
                Q.push({max(newd+1,a[x][y-1]+1),{x,y-1}});
                dist[x][y-1]=max(newd+1,a[x][y-1]+1);
            }
            if(x+1<n&&dist[x+1][y]>max(newd+1,a[x+1][y]+1)){
                Q.push({max(newd+1,a[x+1][y]+1),{x+1,y}});
                dist[x+1][y]=max(newd+1,a[x+1][y]+1);
            }
        }
        return dist[n-1][m-1];
    }
};
