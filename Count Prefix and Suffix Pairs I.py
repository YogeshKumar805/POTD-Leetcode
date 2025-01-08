class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        count = 0

    # Loop through all pairs of indices (i, j) where i < j
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
            # Check if words[i] is both a prefix AND a suffix of words[j]
                if words[j].startswith(words[i]) and words[j].endswith(words[i]):
                # Yo, we found a match! Increment the count.
                    count += 1

    # Return the total count of lit pairs
        return count
