const highestPeak = (isWater) => {
    const q = isWater.map((row, i) => row.map((v, j) => v ? [i, j] : 0)).flat().filter(Boolean);
    const map = isWater.map(row => row.map(_ => 0));
    for (let n = 0; q.length > n;) {
        const [i, j] = q[n++]
        const level = map[i][j] + 1;
        [[1, 0], [-1, 0], [0, -1], [0, 1]]
            .map(([dx, dy])=>[i + dx, j + dy])
            .filter(([x, y]) => 0 === isWater[x]?.[y] && !map[x][y])
            .forEach(([x, y]) => (map[x][y] = level, q.push([x, y])));
    }
    return map;
};
