class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd = ranges::count_if(arr, [sum = 0](int x) mutable { return (sum += x) & 1; });  // odd prefix sums
        long long even = arr.size() + 1 - odd;  // the empty prefix is even
        return odd * even % 1'000'000'007;
    }
};
