class Solution {
    public String clearStars(String s) {
        int n = s.length(); // Gets the length of the string
        PriorityQueue<Character> charQueue = new PriorityQueue<>(); // Creates a priority queue to store characters (letters)
        Map<Character, Deque<Integer>> charMap = new HashMap<>(); // Creates a map to store characters and their indices
        boolean[] keep = new boolean[n]; // Creates a boolean array to mark which characters to keep
        Arrays.fill(keep, true); // Fills the array with true to initially keep all characters

        for (int i = 0; i < n; i++) { // Iterates through each character in the string
            char c = s.charAt(i); // Gets the current character
            if (c == '*') { // If the character is an asterisk
                if (!charQueue.isEmpty()) { // If the priority queue is not empty (meaning there's something to erase)
                    char smallest = charQueue.peek(); // Looks at the smallest character in the queue
                    int indexToRemove = charMap.get(smallest).removeLast(); // Gets the index of this smallest character from the map
                    keep[i] = false; // Removes the asterisk (marks it as not to be kept)
                    keep[indexToRemove] = false; // Removes the smallest character (marks it as not to be kept)
                    charQueue.remove(smallest); // Removes smallest from queue
                } else { // If the queue is empty (nothing to erase)
                    keep[i] = false; // Just remove the asterisk
                }
            } else { // If the character is not an asterisk (a regular letter)
                charQueue.offer(c); // Adds the character to the priority queue
                charMap.putIfAbsent(c, new ArrayDeque<>()); // If the character is not in the map, create a queue of indices for it
                charMap.get(c).add(i); // Adds the index of the character to the queue
            }
        }

        StringBuilder result = new StringBuilder(); // Creates a StringBuilder to build the resulting string
        for (int i = 0; i < n; i++) { // Iterates through the keep array
            if (keep[i]) { // If the character should be kept
                result.append(s.charAt(i)); // Adds the character to the resulting string
            }
        }

        return result.toString(); // Returns the resulting string
    }
}
