class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix_sum = [0] * (n + 1)  # Prefix sum array
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]

        # Monotonic deque to store indices of prefix_sum
        dq = deque()
        result = float('inf')  # Initialize with infinity

        for i in range(n + 1):
            # Check if any subarray satisfies the condition
            while dq and prefix_sum[i] - prefix_sum[dq[0]] >= k:
                result = min(result, i - dq.popleft())

            # Maintain increasing order in the deque
            while dq and prefix_sum[i] <= prefix_sum[dq[-1]]:
                dq.pop()

            dq.append(i)

        return result if result != float('inf') else -1
