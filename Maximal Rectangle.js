var maximalRectangle = function (aa) {
    let m = aa.length,
        n = aa[0].length;

    let widthOnLeftTillHere = Array.from({ length: m }, () =>
        new Array(n).fill(0)
    );
    for (let r = 0; r < m; r++)
        for (let c = 0; c < n; c++)
            if (aa[r][c] === "1") {
                widthOnLeftTillHere[r][c] =
                    (widthOnLeftTillHere[r][c - 1] || 0) + 1;
            }

    let maxArea = 0;
    for (let r = 0; r < m; r++)
        for (let c = 0; c < n; c++)
            if (aa[r][c] === "1") {
                let minWidthGoingUp = Infinity;
                let increasingHeight = 1;
                for (let r2 = r; r2 >= 0; r2--, increasingHeight++) {
                    minWidthGoingUp = Math.min(
                        minWidthGoingUp,
                        widthOnLeftTillHere[r2][c]
                    );
                    maxArea = Math.max(
                        maxArea,
                        minWidthGoingUp * increasingHeight
                    );
                }
            }
    return maxArea;
};
