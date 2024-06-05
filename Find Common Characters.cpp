class Solution {
public:
    // time/space: O(nk)/O(1)
    vector<string> commonChars(vector<string>& words) {
        // find the minimum count for each character in all words
        vector<int> minCount(26, INT_MAX);
        for (auto& word : words) {
            // count the character in the word
            vector<int> count(26, 0);
            for (auto& c : word) count[c - 'a']++;
            for (int c = 0; c < 26; c++) minCount[c] = min(minCount[c], count[c]);
        }

        // generate the result
        vector<string> result;
        for (int c = 0; c < 26; c++) {
            for (int i = 0; i < minCount[c]; i++) result.push_back(string(1, 'a' + c));
        }
        return result;
    }
};
