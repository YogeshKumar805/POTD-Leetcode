var findXSum = function (nums, k, x) {
    const n = nums.length;
    const result = [];
    for (let start = 0; start + k <= n; start++) {
        const counts = new Array(51).fill(0);
        let windowSum = 0;
        for (let i = start; i < start + k; i++) {
            counts[nums[i]]++;
            windowSum += nums[i];
        }
        const freqList = [];
        for (let val = 1; val <= 50; val++) {
            if (counts[val] > 0) freqList.push([counts[val], val]);
        }
        if (freqList.length <= x) {
            result.push(windowSum);
        } else {
            freqList.sort((p, q) => (q[0] - p[0] || q[1] - p[1]));
            let xSum = 0;
            for (let i = 0; i < x; i++) xSum += freqList[i][0] * freqList[i][1];
            result.push(xSum);
        }
    }
    return result;
};
