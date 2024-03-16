# POTD-Leetcode
Daily Problem Of The Day
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        lookup={0:-1}
        ans=0 #max_len
        cur_sum=0
        n=len(nums)
        for i in range(n):
            if nums[i]==0:
                cur_sum-=1
            else:
                cur_sum+=1  
            if cur_sum==0:
                ans=i+1
            elif cur_sum in lookup:
                ans=max(ans,i-lookup[cur_sum])
            else:
                lookup[cur_sum]=i
        return ans                      
