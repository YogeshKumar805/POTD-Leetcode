class Solution:
    def findSmallestInteger(self, nums: list[int], value: int) -> int:
        remainder_count = [0] * value

        for num in nums:
            rem = ((num % value) + value) % value
            remainder_count[rem] += 1

        result = 0
        while remainder_count[result % value] > 0:
            remainder_count[result % value] -= 1
            result += 1

        return result
