/**
 * @param {string[]} words
 * @param {number[]} groups
 * @return {string[]}
 */
var getWordsInLongestSubsequence = function(words, groups) {
    const n = words.length;
    const next = Array(n).fill(n);
    const dp = Array(n).fill(1);
    const maskMap = new Map();
    let bestStart = 0;

    for (let i = n - 1; i >= 0; i--) {
        const word = words[i];
        const len = word.length;
        let fullMask = BigInt(0);
        const charMasks = Array(len).fill(BigInt(0));

        // Encode word into bitmask
        for (let j = 0; j < len; j++) {
            const shift = BigInt(word.charCodeAt(j) - 'a'.charCodeAt(0) + 1) << BigInt(5 * j);
            charMasks[j] = shift;
            fullMask |= shift;
        }

        let maxLen = 1;
        let nextIndex = n;

        // Try all Hamming-1 mutations
        for (let j = 0; j < len; j++) {
            const alteredMask = fullMask ^ charMasks[j];
            if (maskMap.has(alteredMask)) {
                const candidates = maskMap.get(alteredMask);
                for (const idx of candidates) {
                    if (groups[i] !== groups[idx] && dp[idx] + 1 > maxLen) {
                        maxLen = dp[idx] + 1;
                        nextIndex = idx;
                    }
                }
            }
        }

        dp[i] = maxLen;
        next[i] = nextIndex;
        if (dp[i] > dp[bestStart]) bestStart = i;

        // Insert this word's altered masks into map
        for (let j = 0; j < len; j++) {
            const alteredMask = fullMask ^ charMasks[j];
            if (!maskMap.has(alteredMask)) {
                maskMap.set(alteredMask, []);
            }
            maskMap.get(alteredMask).push(i);
        }
    }

    const result = [];
    for (let i = bestStart; i < n; i = next[i]) {
        result.push(words[i]);
    }

    return result;
};
