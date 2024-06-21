class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m){
     // Calculate the initial satisfaction without using the grumpy technique
        int curr_sum=0;
        for(int i=0; i<c.size(); i++){
            if(g[i]==0) curr_sum+=c[i];   
        }
   // Calculate the maximum possible increase using the grumpy technique
       int max_increase=0, current_window_sum=0;
   for (int i = 0; i < c.size(); i++) {
            if (g[i] == 1) {
                current_window_sum += c[i]; // Add grumpy customer satisfaction to the window
            }
            if (i >= m && g[i - m] == 1) {
                current_window_sum -= c[i - m]; // Remove the element that is out of the window
            }
            max_increase = max(max_increase, current_window_sum);
        }
        return curr_sum + max_increase;
    }
};
