class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        // HashMap to store the coordinates of each value in the matrix
        HashMap<Integer, int[]> map = new HashMap<>();
        // Arrays to track the count of marked cells for each row and column
        int[] row = new int[mat.length];
        int[] col = new int[mat[0].length];

        // Populate the HashMap with matrix value coordinates
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                int[] coordinate = new int[2];
                coordinate[0] = i;
                coordinate[1] = j;
                map.put(mat[i][j], coordinate);
            }
        }

        // Iterate through the array and track row/column completions
        for (int i = 0; i < arr.length; i++) {
            int[] coordinate = map.get(arr[i]);
            int r = coordinate[0];
            int c = coordinate[1];

            // Increment row and column counts
            row[r]++;
            col[c]++;

            // Check if the current row or column is fully marked
            if (row[r] == mat[0].length || col[c] == mat.length) {
                return i;
            }
        }

        // Default return value if no row/column is fully marked
        return 1;
    }
}
