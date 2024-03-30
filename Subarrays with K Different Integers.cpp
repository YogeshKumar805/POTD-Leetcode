#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
private:
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0, result = 0;
        
        while (right < n) {
            if (freq[nums[right]] == 0)
                count++;
            freq[nums[right]]++;
            
            while (count > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    count--;
                left++;
            }
            
            // At this point, the window [left, right] has at most k distinct integers.
            // So, all subarrays ending at index 'right' with at most k distinct integers are valid.
            result += right - left + 1;
            
            right++;
        }
        
        return result;
    }
};
