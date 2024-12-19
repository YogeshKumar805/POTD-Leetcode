class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
       vector<int>filled(arr.size(),0);
        for(int i=0;i<n;i++){
            filled[arr[i]]++;
                    int cnt=0;
                for(int j=0;j<=i;j++){
                    cnt+=filled[j];
                }
                if(cnt==i+1)ans++;
            
        }

return ans;
        
    }
};
