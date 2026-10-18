class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        n = len(nums)
        born = [-1] * (n + 2)  # insertion time of each value; the walls 0 and n + 1 come before everything
        for t, x in enumerate(nums):
            born[x] = t

        sizes, stack = 1, [0]  # product of subtree sizes; values with increasing insertion times
        for v in range(1, n + 2):
            while born[stack[-1]] > born[v]:  # v is the right wall of the value on top
                stack.pop()
                sizes *= v - stack[-1] - 1  # and the value below it is the left wall
            stack.append(v)

        return (factorial(n) // sizes - 1) % (10**9 + 7)
