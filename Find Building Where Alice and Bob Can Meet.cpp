class Solution
{
    using ll = long long;
    ll tree[20 * 10000 + 14];

    void build(int si, int ss, int se, vector<int> &arr)
    {
        if (ss == se)
            tree[si] = arr[ss - 1];
        else
        {
            int sm = (ss + se) >> 1;
            build(2 * si, ss, sm, arr);
            build(2 * si + 1, sm + 1, se, arr);
            tree[si] = max(tree[2 * si], tree[2 * si + 1]);
        }
    }

    ll find(int si, int ss, int se, int l, int r, int c)
    {
        if (ss > r or se < l)
            return INT_MAX;
        if (ss >= l and se <= r)
        {
            if (tree[si] <= c)
                return INT_MAX;
            if (ss == se)
                return ss;
            int sm = (ss + se) >> 1;
            if (tree[2 * si] > c)
                return find(2 * si, ss, sm, l, r, c);
            return find(2 * si + 1, sm + 1, se, l, r, c);
        }
        int sm = (ss + se) >> 1;
        return min(find(2 * si, ss, sm, l, r, c), find(2 * si + 1, sm + 1, se, l, r, c));
    }

public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        build(1, 1, heights.size(), heights);
        vector<int> ans;
        for (auto &q : queries)
        {
            int a = q[0] + 1, b = q[1] + 1;
            if (a > b)
                swap(a, b);
            if (a == b)
                ans.push_back(b - 1);
            else if (heights[b - 1] > heights[a - 1])
                ans.push_back(b - 1);
            else
            {
                int mx = max(heights[b - 1], heights[a - 1]);
                int idx = find(1, 1, heights.size(), b + 1, heights.size(), mx) - 1;
                if (idx >= size(heights))
                    idx = -1;
                ans.push_back(idx);
            }
        }
        return ans;
    }
};
