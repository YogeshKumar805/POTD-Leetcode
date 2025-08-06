class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int root=floor(sqrt(n));
        vector<int> v(root+2,0); // vector to store max of elements in each block of size (√n)
        // storing max of every block
        for(int i=0;i<n;i++) { 
            // if index of cur element is 'i' in baskets array then its block number will be (i/√n) 
            v[i/root]=max(v[i/root],baskets[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            int ind=-1;
            for(int j=0;j<root+2;j++) { // find if any block has max_element>=fruits[i]
                if(v[j]>=fruits[i]) {
                    ind=j;
                    break;
                }
            }
            if(ind==-1) {
                 // if the max of all blocks is less than fruits[i] i.e. we cannot pick fruits of this type
                ans++;
                continue;
            }
            // we have first element greater than fruits[i] in (ind)th block of baskets
            for(int j=root*ind;j<(ind+1)*root;j++) {
                // iterate over all elements is (ind)th block and find first element >= fruits[i]
                if(baskets[j]>=fruits[i]) {
                    baskets[j]=0; // after using basket[j] set its capacity to 0 as we cannot use it again
                    break;
                }
            }
            v[ind]=0; // recalculate max of (ind)th block as we have changed one element in it
            for(int j=root*ind;j<min(n,(ind+1)*root);j++) {
                v[ind]=max(v[ind],baskets[j]);
            }
        }
        return ans;
    }
};
