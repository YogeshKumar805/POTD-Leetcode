class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i, j = 0, 0  # Pointers for str1 and str2
        
        while i < len(str1) and j < len(str2):
            # Check if current character matches or if incrementing matches
            if str1[i] == str2[j] or chr((ord(str1[i]) - ord('a') + 1) % 26 + ord('a')) == str2[j]:
                j += 1  # Move to the next character in str2 if matched
            i += 1  # Always move to the next character in str1
        
        # If we have matched all characters of str2, return True
        return j == len(str2)
