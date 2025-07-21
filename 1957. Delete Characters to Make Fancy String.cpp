class Solution {
public:
    string makeFancyString(string s) {
        // Handle edge cases: empty string or single character
        if (s.length() <= 2) {
            return s;
        }
        
        // Result string to build our fancy string
        string result = "";
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // Get the current character
            char currentChar = s[i];
            
            // Check if adding this character would create three consecutive identical characters
            // We need at least 2 characters in result to make this check
            if (result.length() >= 2 && 
                result[result.length() - 1] == currentChar && 
                result[result.length() - 2] == currentChar) {
                // Skip this character because it would create three consecutive identical characters
                continue;
            }
            
            // Safe to add this character - it won't create three consecutive identical characters
            result += currentChar;
        }
        
        return result;
    }
};
