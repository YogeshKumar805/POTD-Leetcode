class Solution:
    def clearDigits(self, s: str) -> str:
        stack = []
        
        for char in s:
            if char.isdigit():
                # Find the closest non-digit character to the left
                while stack and stack[-1].isdigit():
                    stack.pop()
                # Remove the closest non-digit character
                if stack:
                    stack.pop()
            else:
                stack.append(char)
        
        return ''.join(stack)
