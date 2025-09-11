class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        unordered_set<char> v = {'A','E','I','O','U','a','e','i','o','u'};

        // Step 1: Collect vowels
        for (char c : s) {
            if (v.count(c)) vowels.push_back(c);
        }

        // Step 2: Sort vowels by ASCII value
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in original string
        int j = 0;
        for (char &c : s) {
            if (v.count(c)) {
                c = vowels[j++];
            }
        }

        return s;
    }
};
