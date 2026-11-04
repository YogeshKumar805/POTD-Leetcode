class Window {
    multiset<int> s;
    multiset<int>::iterator mid;  // the (h+1)-th smallest: everything before it is the low half
    long long low, total;
    int odd;

public:
    Window(vector<int>::const_iterator first, vector<int>::const_iterator last)
        : s(first, last), odd(s.size() & 1) {
        mid = next(s.begin(), s.size() / 2);
        low = accumulate(s.begin(), mid, 0LL);
        total = accumulate(s.begin(), s.end(), 0LL);
    }

    long long cost() const {  // larger half minus smaller half
        return total - 2 * low - odd * *mid;
    }

    long long slide(int out, int in) {
        s.insert(in);
        if (in < *mid)  // in joins the low half and pushes its largest up
            low += in - *--mid;
        if (out < *mid) {  // out leaves the low half: mid moves down into it
            low += *mid++ - out;
            s.erase(s.find(out));
        } else if (out == *mid) {
            mid = s.erase(mid);
        } else {
            s.erase(s.find(out));
        }
        total += in - out;
        return cost();
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        Window win(nums.begin(), nums.begin() + x);
        vector<long long> cost{win.cost()};
        for (int i = x; i < n; ++i)
            cost.push_back(win.slide(nums[i - x], nums[i]));

        vector<long long> best(n + 1);  // best[i]: min ops for the windows placed so far inside nums[0..i)
        for (int j = 0; j < k; ++j) {
            vector<long long> layer(n + 1, LLONG_MAX / 2);
            for (int i = x; i <= n; ++i)
                layer[i] = min(layer[i - 1], best[i - x] + cost[i - x]);
            best = move(layer);
        }
        return best[n];
    }
};
