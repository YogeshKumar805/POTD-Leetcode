class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        
        for char in expression:
            if char == ')':
                # We reached the end of a subexpression, time to evaluate
                sub_expr = []
                while stack[-1] != '(':
                    sub_expr.append(stack.pop())
                stack.pop()  # Remove the opening '('
                operator = stack.pop()  # Get the operator before '('
                
                if operator == '!':
                    # NOT operator only works on one operand
                    result = not self.to_bool(sub_expr[0])
                elif operator == '&':
                    # AND operator works on all operands and returns True if all are True
                    result = all(self.to_bool(val) for val in sub_expr)
                elif operator == '|':
                    # OR operator works on all operands and returns True if any is True
                    result = any(self.to_bool(val) for val in sub_expr)
                
                # Push the result back onto the stack
                stack.append('t' if result else 'f')
            elif char not in (',', ' '):  # Ignore commas and spaces
                stack.append(char)
        
        # At the end, the stack will have one value which is the result
        return self.to_bool(stack.pop())
    
    def to_bool(self, char: str) -> bool:
        return char == 't'

