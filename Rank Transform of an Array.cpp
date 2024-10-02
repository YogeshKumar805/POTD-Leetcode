class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            vec[i]=i;
        }
        sort(vec.begin(),vec.end(),[&](int&a,int&b){
            return arr[a]<arr[b];
        });
        int last;
        if(n>0){
            last=arr[vec[0]];
            arr[vec[0]]=1;
        }
        for(int i=1;i<n;i++){
            if(arr[vec[i]]==last){
                last=arr[vec[i]];
                arr[vec[i]]=arr[vec[i-1]];
            }
            else{
                last=arr[vec[i]];
                arr[vec[i]]=arr[vec[i-1]]+1;
            }
        }
        return arr;
    }
};
