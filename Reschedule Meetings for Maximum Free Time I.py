class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: list[int], endTime: list[int]) -> int:
        n = len(startTime)
        res = 0
        sum_durations = [0] * (n + 1)

        for i in range(n):
            sum_durations[i + 1] = sum_durations[i] + endTime[i] - startTime[i]

        for i in range(k - 1, n):
            right = eventTime if i == n - 1 else startTime[i + 1]
            left = 0 if i == k - 1 else endTime[i - k]
            free_time = right - left - (sum_durations[i + 1] - sum_durations[i - k + 1])
            res = max(res, free_time)

        return res
