class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        # for flipping only 1 item, it is just the number of 0s
        if k == 1:
            return nums.count(0)
        n = len(nums)
        it = enumerate(nums)

        # run until we can flip the complete k-window
        # when starting a flip, mark it with 2 in the index + k item
        result = 0
        flipCnt = 0
        for _ in range(n - k):
            index, x = next(it)
            # end of some previous flip
            if x & 2 == 2:
                flipCnt -= 1
            # check if not covered by previous flips
            if ((flipCnt ^ x) & 1) == 0:
                # add a new flip
                nums[index + k] |= 2
                flipCnt += 1
                result += 1
        # check the last complete window
        index, x = next(it)
        if x & 2 == 2:
            flipCnt -= 1
        if ((flipCnt ^ x) & 1) == 0:
            flipCnt += 1
            result += 1
        # check the tail of the array, that everything comes out as 1
        for index, x in it:
            if x & 2 == 2:
                flipCnt -= 1
            if ((flipCnt ^ x) & 1) == 0:
                return -1
        return result
