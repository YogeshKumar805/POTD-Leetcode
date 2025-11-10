class Solution
{
public:
    [[nodiscard]] static constexpr uint32_t minOperations(
        std::vector<int>& nums) noexcept
    {
        uint32_t s = 0, r = 0;
        for (auto v : nums)
        {
            if (v)
            {
                while (s && nums[s - 1] > v)
                {
                    ++r;
                    --s;
                }

                if (!s || nums[s - 1] != v)
                {
                    nums[s++] = v;
                }
            }
            else
            {
                r += s;
                s = 0;
            }
        }

        return r + s;
    }
};

#ifndef __clang__
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
#endif
