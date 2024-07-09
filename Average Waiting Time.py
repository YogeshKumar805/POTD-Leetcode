class Solution(object):
    def averageWaitingTime(self, customers):
        sum, cur = 0.0, 0
        for vec in customers:
            if vec[0] > cur:
                sum += vec[1]
                cur = vec[0] + vec[1]
            else:
                cur += vec[1]
                sum += cur - vec[0]
        return sum/len(customers)
