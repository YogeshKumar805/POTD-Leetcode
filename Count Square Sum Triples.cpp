class Solution {
public:
    int countTriples(int n) {
        vector<bool> isSquare(n * n + 1, false);
        for (int i = 1; i <= n; i++) {
            isSquare[i * i] = true;
        }
        
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int sum = a * a + b * b;
                if (sum <= n * n && isSquare[sum])
                    count++;
            }
        }
        return count;
    }
};
