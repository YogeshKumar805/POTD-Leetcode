class Solution {
    public int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        for(int i = 3; i <= n + 2; i++){
            c += a + b;
            b = c - a - (a=b);
        }
        return a;
    }
}
