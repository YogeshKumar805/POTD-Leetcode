class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> deadSet = new HashSet<>(Arrays.asList(deadends));
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        queue.offer("0000");
        visited.add("0000");
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String current = queue.poll();
                if (deadSet.contains(current)) continue;
                if (current.equals(target)) return level;

                for (int j = 0; j < 4; j++) {
                    char[] currentArray = current.toCharArray();
                    char originalChar = currentArray[j];

                    // Rotate the wheel forward
                    currentArray[j] = (char) ((currentArray[j] - '0' + 1) % 10 + '0');
                    String next = new String(currentArray);
                    if (!visited.contains(next) && !deadSet.contains(next)) {
                        queue.offer(next);
                        visited.add(next);
                    }

                    // Rotate the wheel backward
                    currentArray[j] = originalChar;
                    currentArray[j] = (char) ((currentArray[j] - '0' + 9) % 10 + '0');
                    next = new String(currentArray);
                    if (!visited.contains(next) && !deadSet.contains(next)) {
                        queue.offer(next);
                        visited.add(next);
                    }

                    currentArray[j] = originalChar; // Restore the original state
                }
            }
            level++;
        }
        return -1; // Target not reachable
    }
}
