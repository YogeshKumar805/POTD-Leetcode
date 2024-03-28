class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        int maxLen{};
        
        for(int right = 0, left = 0 ; right < (int)nums.size() ; right++)
        {
            freq[nums[right]]++;
            
            while(freq[nums[right]] > k)
                freq[nums[left++]]--;
            
            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
};
