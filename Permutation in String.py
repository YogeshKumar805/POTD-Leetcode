class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # Edge case: if s1 is longer than s2, s1's permutation can't be in s2
        if len(s1) > len(s2):
            return False
        
        # Create frequency count for s1
        s1_count = Counter(s1)
        
        # Initialize a sliding window for s2 (first window of size len(s1))
        window_count = Counter(s2[:len(s1)])
        
        # Compare the first window
        if s1_count == window_count:
            return True
        
        # Start sliding the window across s2
        for i in range(len(s1), len(s2)):
            # Include a new character from the right (expand the window)
            window_count[s2[i]] += 1
            
            # Remove the character that's left behind (contract the window)
            window_count[s2[i - len(s1)]] -= 1
            
            # Clean up the zero count to avoid comparing unnecessary keys
            if window_count[s2[i - len(s1)]] == 0:
                del window_count[s2[i - len(s1)]]
            
            # Compare the window with s1_count
            if window_count == s1_count:
                return True
        
        # If no permutation was found
        return False
