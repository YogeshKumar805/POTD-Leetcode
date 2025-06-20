const maxDistance = (s, k) => {
    const dir = {
        'N': [0, 1],
        'S': [0, -1],
        'E': [1, 0],
        'W': [-1, 0]
    }

    let [p, q] = [0, 0];
    let maxDist = 0;

    for (let i = 0; i < s.length; i++) {
        const [u, v] = dir[s[i]];
        p += u;
        q += v;

        const base = Math.abs(p) + Math.abs(q);
        const extra = Math.min(2 * k, i + 1 - base);

        maxDist = Math.max(maxDist, base + extra);
    }
    return maxDist;
};
