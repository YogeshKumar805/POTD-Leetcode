class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainder_count = [0] * k
        
        # Count frequencies of remainders
        for num in arr:
            remainder = num % k
            # Adjust remainder for negative numbers
            if remainder < 0:
                remainder += k
            remainder_count[remainder] += 1
        
        # Check pairs of remainders
        if remainder_count[0] % 2 != 0:
            return False  # The remainder 0 needs to pair with itself, so must be even
        
        # Check pairs for other remainders
        for i in range(1, (k // 2) + 1):
            if remainder_count[i] != remainder_count[k - i]:
                return False
        
        return True
