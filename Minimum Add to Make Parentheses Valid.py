class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        # Initialize balance variables for unmatched parentheses
        left_balance = 0  # Tracks unmatched '('
        right_balance = 0  # Tracks unmatched ')'
        
        # Traverse through the string
        for char in s:
            if char == '(':
                left_balance += 1  # Add an unmatched '('
            elif char == ')':
                if left_balance > 0:
                    # If there is an unmatched '(', pair it with this ')'
                    left_balance -= 1
                else:
                    # If no unmatched '(', this ')' is unmatched
                    right_balance += 1
        
        # The total moves needed is the sum of unmatched '(' and ')'
        return left_balance + right_balance
