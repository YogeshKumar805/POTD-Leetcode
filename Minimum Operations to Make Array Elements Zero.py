class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        count = 0

        def get_divisions(num: int) -> int:
            return math.floor(math.log(num, 4)) + 1

        for left, right in queries:
            divisions = 0
            log4_left = get_divisions(left)
            log4_right = get_divisions(right)
            four_power = 4 ** log4_left

            for div in range(log4_left, log4_right + 1):
                mid = min(right, four_power - 1)
                divisions += (mid - left + 1) * div
                left = four_power
                four_power *= 4
                
            count += (divisions + 1) // 2
        
        return count
