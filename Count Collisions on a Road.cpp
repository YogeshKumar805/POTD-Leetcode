class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        bool accident;
        accident = false;
        for(int i = 1; i < n; i ++){
            if(directions[i] == 'L'){
                if(directions[i - 1] != 'L' || accident){
                    ans += 1;
                    accident = true;
                }
            }
        }
        accident = false;
        for(int i = n - 2; i >= 0; i --){
            if(directions[i] == 'R'){
                if(directions[i + 1] != 'R' || accident){
                    ans += 1;
                    accident = true;
                }
            }
        }
        return ans;
    }
};
