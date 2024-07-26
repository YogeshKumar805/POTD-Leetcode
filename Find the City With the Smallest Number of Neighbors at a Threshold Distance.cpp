class Solution {
public:
    int n, distanceThreshold;
    int dist[100][100];
    
    void FW(vector<vector<int>>& edges){
        fill(&dist[0][0], &dist[0][0]+100*100, 1e9);
        for (int i = 0; i < n; i++) 
            dist[i][i] = 0;
        for (auto& e : edges){
            int u=e[0], v = e[1], w = e[2];
            if (w <= distanceThreshold) //drop large weights
                dist[u][v]=dist[v][u]=w;
        }
        // Main loop
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this->n = n;
        this->distanceThreshold = distanceThreshold;
        FW(edges);
        
        int min_cnt = n, city = -1;
        for (int i = 0; i <n ; i++){
            int cnt = -1;  // i itself doesn't count
            for (int j = 0; j < n; j++){
                if (dist[i][j] <= distanceThreshold) 
                    cnt++;
            }
            if (cnt <=min_cnt ){
                min_cnt=cnt;
                city=i;
            }
        }
        return city;
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}(); 
