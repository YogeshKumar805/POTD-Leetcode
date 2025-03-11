/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function (s) {
    let count = { 'a': 0, 'b': 0, 'c': 0 }; // Track character count
    let left = 0, result = 0;

    for (let right = 0; right < s.length; right++) {
        count[s[right]]++; // Expand window

        // When all characters are in the window, move left pointer
        while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
            result += s.length - right; // All substrings from left to end are valid
            count[s[left]]--;
            left++; // Shrink window
        }
    }

    return result;
};
