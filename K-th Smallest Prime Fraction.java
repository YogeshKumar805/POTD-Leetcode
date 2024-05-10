class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        
        int n = arr.length;
        
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((x, y) -> Double.compare((double)y[0] / y[1], (double)x[0] / x[1]));
        
        for (int i = 0 ; i < n ; i++) {
            for  (int j = i+1 ; j < n ; j++) {
                maxHeap.add(new int[] {arr[i], arr[j]});
                if (maxHeap.size() > k) maxHeap.poll();
            }
        }
        
        return maxHeap.peek();
    }
}
