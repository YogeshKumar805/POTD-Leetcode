class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            int x = arr[i];
            for(int j=i+1;j<n;j++){
                x = x^arr[j];
                if(x == 0)count += (j-i);
            }
        }
        return count;
    }
};
