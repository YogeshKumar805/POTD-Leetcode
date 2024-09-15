class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        # Vowel to bit index mapping
        vowels = {'a': 0, 'e': 1, 'i': 2, 'o': 3, 'u': 4}
        # Dictionary to store the first occurrence of each bitmask
        bitmask_position = {0: -1}  # Initialize bitmask 0 at index -1 to handle full valid substring
        current_bitmask = 0
        max_length = 0
        
        for i, char in enumerate(s):
            if char in vowels:
                # Toggle the bit corresponding to the vowel
                current_bitmask ^= (1 << vowels[char])
            
            if current_bitmask in bitmask_position:
                # Calculate the length of the substring if the bitmask has been seen before
                max_length = max(max_length, i - bitmask_position[current_bitmask])
            else:
                # Store the first occurrence of the bitmask
                bitmask_position[current_bitmask] = i
        
        return max_length
