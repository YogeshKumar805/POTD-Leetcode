#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> M(26, vector<int>(2));

        for (int i = 0; i < 26; i++) {
            M[i][0] = INT_MAX; // First occurrence
            M[i][1] = INT_MIN; // Last occurrence
        }

        // Store first and last occurrences of each character
        for (int i = 0; i < s.length(); i++) {
            int t = s[i] - 'a';
            M[t][0] = min(M[t][0], i);
            M[t][1] = max(M[t][1], i);
        }

        vector<pair<int, int>> P;
        for (vector<int> T : M) {
            if (T[0] != INT_MAX) {
                P.push_back({T[0], T[1]});
            }
        }

        sort(P.begin(), P.end());

        int start = P[0].first;
        int end = P[0].second;
        vector<int> ans;

        for (size_t i = 1; i < P.size(); i++) {
            if (P[i].first <= end) { // Merge intervals
                end = max(end, P[i].second);
            } else { // Store partition size
                ans.push_back(end - start + 1);
                start = P[i].first;
                end = P[i].second;
            }
        }

        ans.push_back(end - start + 1);
        return ans;
    }
};
