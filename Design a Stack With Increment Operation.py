class CustomStack:

    def __init__(self, maxSize: int):
        # Initialize stack and the increments helper list
        self.stack = []
        self.inc = [0] * maxSize  # inc[i] tracks the increment to be applied to stack[i]
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        # Add element to stack if not full
        if len(self.stack) < self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        # Pop element from the top and apply increment if needed
        if not self.stack:
            return -1  # Stack is empty
        
        index = len(self.stack) - 1
        result = self.stack.pop() + self.inc[index]  # Add any pending increment
        
        # Pass the current increment downwards if there is any remaining stack
        if index > 0:
            self.inc[index - 1] += self.inc[index]
        
        # Reset the current increment for the popped element
        self.inc[index] = 0
        
        return result

    def increment(self, k: int, val: int) -> None:
        # Increment the bottom k elements
        # If k is larger than the stack size, increment all elements
        limit = min(k, len(self.stack))
        if limit > 0:
            self.inc[limit - 1] += val  # Add the increment to the last affected element


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
