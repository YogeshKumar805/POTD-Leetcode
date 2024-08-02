/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function(nums) {
    const n = nums.length;
    
    const windowSize = nums.reduce((sum, num) => sum + num, 0);
    
    let slideWindow = nums.slice(0, windowSize);

    let slide1s = slideWindow.reduce((sum, num) => sum + num, 0);
    let max1s = slide1s;
    for (let i = 0; i < nums.length; i++) {
        if (nums[(windowSize+i) % n] === 1) {
            slide1s++; // Adding New one
        }

        if (nums[i] === 1) {
            slide1s--; // Removing old one
        }

        max1s = Math.max(max1s, slide1s);
    }

    return windowSize - max1s; // Minimum swaps;
};
