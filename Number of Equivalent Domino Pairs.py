class Solution:
    def numEquivDominoPairs(self, dominoes):
        from collections import defaultdict
        count_map = defaultdict(int)
        count = 0
        for a, b in dominoes:
            key = tuple(sorted((a, b)))
            count_map[key] += 1
        for freq in count_map.values():
            count += freq * (freq - 1) // 2
        return count
