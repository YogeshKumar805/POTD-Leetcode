class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int start = values[0];
        int max = 0;

        for(int j = 1; j<values.length; j++){
            int val = values[j] - j;
            if(start + val > max){
                max = start + val;
            }
            if(values[j]+j > start){
                start = values[j]+j;
            } 
        }
        return max; 
    }
}
