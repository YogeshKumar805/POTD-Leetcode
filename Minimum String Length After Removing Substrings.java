class Solution {
    public int minLength(String s) {
        Stack<Character> stack = new Stack<>();

        // Iterate through each character in the string
        for (char c : s.toCharArray()) {
            // Check if we have "AB" or "CD" patterns to remove
            if (!stack.isEmpty()) {
                char top = stack.peek();
                if ((top == 'A' && c == 'B') || (top == 'C' && c == 'D')) {
                    stack.pop(); // Remove the pair "AB" or "CD"
                    continue;    // Move to the next character
                }
            }
            // Push the current character onto the stack if no pair was removed
            stack.push(c);
        }

        // The size of the stack is the minimum possible length of the resulting string
        return stack.size();
    }
}
