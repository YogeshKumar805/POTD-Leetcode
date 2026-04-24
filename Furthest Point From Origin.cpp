class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x=0, r=0;
        for(char c: moves){
            x+=(c=='R')-(c=='L');
            r+=c=='_';
        }
        return abs(x)+r;
    }
};
