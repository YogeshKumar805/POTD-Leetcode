class Solution:
    def bestClosingTime(self, customers: str) -> int:
        Y = customers.count('Y')
        n = 0
        C = Y
        Ans = 0

        for i in range(len(customers)):
            if customers[i] == 'Y':
                Y -= 1
            else:
                n += 1

            if n + Y < C:
                C = n + Y
                Ans = i + 1

        return Ans
