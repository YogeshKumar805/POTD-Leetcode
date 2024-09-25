class TrieNode:
    def __init__(self):
        self.children = {}
        self.prefix_count = 0

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        # Step 1: Build the Trie
        root = TrieNode()
        
        # Insert each word into the trie and track the prefix counts
        for word in words:
            current = root
            for char in word:
                if char not in current.children:
                    current.children[char] = TrieNode()
                current = current.children[char]
                current.prefix_count += 1  # Increment the prefix count at each node
        
        # Step 2: For each word, calculate the total prefix score
        result = []
        for word in words:
            current = root
            score = 0
            for char in word:
                current = current.children[char]
                score += current.prefix_count  # Sum the prefix counts for each character in the word
            result.append(score)
        
        return result
