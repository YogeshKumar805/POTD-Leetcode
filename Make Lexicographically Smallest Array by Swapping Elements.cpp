#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Pair each number with its original index
        vector<pair<int, int>> sortedPairs;
        for (int i = 0; i < n; ++i) 
            sortedPairs.emplace_back(nums[i], i);
        
        // Step 2: Sort by number value
        sort(sortedPairs.begin(), sortedPairs.end());

        vector<int> result(n);
        int groupStart = 0;

        for (int i = 0; i < n; ++i) {
            // Step 3: Check if current group ends here
            if (i == n-1 || sortedPairs[i+1].first - sortedPairs[i].first > limit) {
                // Step 4: Collect and sort original indices
                vector<int> indices;
                for (int j = groupStart; j <= i; ++j) 
                    indices.push_back(sortedPairs[j].second);
                sort(indices.begin(), indices.end());
                
                // Step 5: Assign sorted values to sorted indices
                for (int j = 0; j < indices.size(); ++j) 
                    result[indices[j]] = sortedPairs[groupStart + j].first;
                
                groupStart = i + 1; // Next group starts after current
            }
        }
        return result;
    }
};
