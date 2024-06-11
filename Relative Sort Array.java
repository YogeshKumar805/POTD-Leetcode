class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        // Step 1: Create a count array to store the count of each element in arr1
        int[] cnt = new int[1001];
        for (int i : arr1) {
            cnt[i]++;
        }

        // Step 2: Create a result array to store the final sorted elements
        int[] ans = new int[arr1.length];
        int i = 0;

        // Step 3: Place elements of arr2 into the result array
        for (int n : arr2) {
            while (cnt[n] > 0) {
                ans[i] = n;
                cnt[n]--;
                i++;
            }
        }

        // Step 4: Place remaining elements in ascending order
        for (int j = 0; j < cnt.length; j++) {
            while (cnt[j] > 0) {
                ans[i] = j;
                cnt[j]--;
                i++;
            }
        }

        // Return the result array
        return ans;
    }
}
