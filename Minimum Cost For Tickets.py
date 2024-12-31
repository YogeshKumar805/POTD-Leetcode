class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        travel_days_set = set(days)
        last_day = days[-1]
        dp = [0] * (last_day + 1)

        for day in range(1, last_day + 1):
            if day not in travel_days_set:
                dp[day] = dp[day - 1]
            else:
                dp[day] = min(
                    dp[max(0, day - 1)] + costs[0],
                    dp[max(0, day - 7)] + costs[1],
                    dp[max(0, day - 30)] + costs[2]
                )

        return dp[-1]
