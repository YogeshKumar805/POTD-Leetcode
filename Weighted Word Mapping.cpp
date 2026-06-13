class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res(words.size(), 0);
        int i = 0;

        for (auto& word : words) {
            int s = 0;
            for (auto& c : word)
                s += weights[(c & (1 << 5) - 1) - 1];
            res[i++] = 'z' - (s - ((s * 2521) >> (1 << 4)) * 26);
        }

        return res;
    }
};
