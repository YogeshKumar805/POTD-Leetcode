class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n, m = len(nums), len(queries)
        dif_arr = [0] * (n + 1) # available vals at index, + 1 to handle dif_arr[r + 1]
        cur_sum = j = 0 # current sum of queries at index and j for current query

        for i, num in enumerate(nums):
            cur_sum += dif_arr[i] # update cur_sum with vals from index, cur_sum can + or -

            while j < m and cur_sum < num: # while can use a query and num isn't 0
                l, r, val = queries[j]
                j += 1

                if i < l:
                    dif_arr[l] += val # haven't reached range of query, store val at start of range
                elif i <= r:
                    cur_sum += val # l <= i <= r, currently in range of query, apply to cur_sum
                    
                dif_arr[r + 1] -= val # remove val when no longer in range of query

            if cur_sum < num:
                return -1 # wasn't able to make num 0, so invalid
            
        return j # number of queries processed to finish nums
