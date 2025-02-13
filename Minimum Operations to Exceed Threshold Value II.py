class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        tmp = 0

        while nums[0] < k:
            tmp1 = heapq.heappop(nums)
            tmp2 = heapq.heappop(nums)
            heapq.heappush(nums, min(tmp1, tmp2) * 2 + max(tmp1, tmp2))
            tmp += 1

        return tmp
