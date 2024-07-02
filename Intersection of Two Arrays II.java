import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] count = new int[1001];  // Frequency count array for nums1 elements
        List<Integer> intersectionList = new ArrayList<>();  // List to store intersection elements

        // Populate the frequency count array with nums1 elements
        for (int num : nums1) {
            count[num]++;
        }

        // Check nums2 elements against the frequency count array
        for (int num : nums2) {
            if (count[num] > 0) {
                intersectionList.add(num);
                count[num]--;
            }
        }

        // Convert the list to an array and return
        int[] intersectionArray = new int[intersectionList.size()];
        for (int i = 0; i < intersectionList.size(); i++) {
            intersectionArray[i] = intersectionList.get(i);
        }

        return intersectionArray;
    }
}
