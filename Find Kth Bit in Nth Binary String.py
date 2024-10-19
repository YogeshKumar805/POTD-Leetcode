class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        def find_kth_bit_in_sn(n, k):
            # Base case: S1 is "0"
            if n == 1:
                return "0"
            
            # Length of Sn
            length_of_sn = (1 << n) - 1  # 2^n - 1
            
            # Middle element position
            middle = (length_of_sn // 2) + 1
            
            if k == middle:
                return "1"
            elif k < middle:
                # If k is in the first half, it's the same as finding it in S(n-1)
                return find_kth_bit_in_sn(n - 1, k)
            else:
                # If k is in the second half, map it to the corresponding position in reverse(invert(S(n-1)))
                mirrored_position = length_of_sn - k + 1
                # Find the bit in S(n-1) and invert it
                bit = find_kth_bit_in_sn(n - 1, mirrored_position)
                return "1" if bit == "0" else "0"
        
        return find_kth_bit_in_sn(n, k)
