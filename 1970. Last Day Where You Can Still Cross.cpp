class Solution {
public:
    vector<int> p, r;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) p[a] = b;
        else if (r[a] > r[b]) p[b] = a;
        else { p[b] = a; r[a]++; }
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col, top = n, bottom = n + 1;
        p.resize(n + 2); r.assign(n + 2, 0);
        vector<bool> land(n, false);
        iota(p.begin(), p.end(), 0);

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int d = cells.size() - 1; d >= 0; d--) {
            int r0 = cells[d][0] - 1, c0 = cells[d][1] - 1;
            int id = r0 * col + c0;
            land[id] = true;

            for (auto& di : dir) {
                int nr = r0 + di[0], nc = c0 + di[1];
                if (nr >= 0 && nc >= 0 && nr < row && nc < col) {
                    int nid = nr * col + nc;
                    if (land[nid]) unite(id, nid);
                }
            }

            if (r0 == 0) unite(id, top);
            if (r0 == row - 1) unite(id, bottom);

            if (find(top) == find(bottom)) return d;
        }
        return 0;
    }
};
