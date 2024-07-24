class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        mappedNums = {}
        for num in nums:
            if num in mappedNums: continue
            digits = map(int, str(num))
            mappedNum = ''.join(str(mapping[d]) for d in digits)
            mappedNums[num] = int(mappedNum)

        return sorted(nums, key = mappedNums.get)
