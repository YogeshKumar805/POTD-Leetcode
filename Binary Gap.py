class Solution:
    def binaryGap(self, n: int) -> int:
        d, p=0, 32
        while n>0:
            ctz=(n&-n).bit_length()-1
            d=max(d, ctz-p)
            p=ctz
            n&=(n-1)
        return d
