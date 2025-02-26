const maxAbsoluteSum = (nums, s = 0) => {
    nums = nums.map((v, i) => s = s + v);
    return Math.max(...nums, 0) - Math.min(...nums, 0);
};
