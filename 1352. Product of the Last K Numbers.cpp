class ProductOfNumbers {
    vector<int> prefix{1};  // prefix[i]: the product of the first i numbers after the last zero

public:
    void add(int num) {
        if (num == 0)
            prefix = {1};  // a window that reaches this zero is 0, so forget everything before it
        else
            prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n)  // the window reaches back to a zero
            return 0;
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};
