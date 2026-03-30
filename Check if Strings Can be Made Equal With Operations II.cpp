class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string e1, o1, e2, o2;

        for (int i = 0; i < s1.length(); i++) {
            if (i & 1) {
                o1 += s1[i];
                o2 += s2[i];
            } else {
                e1 += s1[i];
                e2 += s2[i];
            }
        }

        sort(e1.begin(), e1.end());
        sort(o1.begin(), o1.end());
        sort(e2.begin(), e2.end());
        sort(o2.begin(), o2.end());

        return e1 == e2 && o1 == o2;
    }
};
