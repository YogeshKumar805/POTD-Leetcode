class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count1 = 0, count0 = 0;
        
        // Count the number of students preferring each type of sandwich
        for (int x : students) {
            if (x)
                count1++;
            else
                count0++;
        }

        // Iterate through the sandwiches
        for (int x : sandwiches) {
            // If the sandwich on top is preferred by a student
            if (x) {
                // If there are still students who prefer this type of sandwich
                if (count1 > 0) {
                    count1--; // Reduce the count of students preferring this type of sandwich
                } else {
                    // If no students prefer this type of sandwich, return the count of students unable to eat
                    return count0;
                }
            } else {
                // If the sandwich on top is not preferred by a student
                // If there are still students who prefer this type of sandwich
                if (count0 > 0) {
                    count0--; // Reduce the count of students preferring this type of sandwich
                } else {
                    // If no students prefer this type of sandwich, return the count of students unable to eat
                    return count1;
                }
            }
        }
        return 0; // If all students can eat, return 0
    }
};
