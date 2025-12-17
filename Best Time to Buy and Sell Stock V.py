class Data:
    def __init__(self, profit, buy, sell):
        self.profit=profit
        self.buy=buy
        self.sell=sell
class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        x0=prices[0]
        dp=[Data(0, -x0, x0) for _ in range(k+1)]
        n=len(prices)
        for i in range(1, n):
            x=prices[i]
            for t in range(k, 0, -1):
                cur=dp[t]
                prevP=dp[t-1].profit
                # close transaction t
                cur.profit=max(cur.profit, cur.buy+x, cur.sell-x)
                # open transaction t
                cur.buy=max(cur.buy,  prevP-x)
                cur.sell=max(cur.sell, prevP+x)
        return dp[-1].profit
