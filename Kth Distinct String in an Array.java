class Solution {
    public String kthDistinct(String[] arr, int k) {
        // Step 1: Count the occurrences of each string
        Map<String, Integer> countMap = new HashMap<>();
        for (String s : arr) {
            countMap.put(s, countMap.getOrDefault(s, 0) + 1);
        }

        // Step 2: Identify distinct strings
        int distinctCount = 0;
        for (String s : arr) {
            if (countMap.get(s) == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return s;
                }
            }
        }

        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
}
