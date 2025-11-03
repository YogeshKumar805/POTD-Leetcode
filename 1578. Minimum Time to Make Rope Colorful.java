class Solution {
    public int minCost(String colors, int[] neededTime) {

        char[] C = colors.toCharArray() ;

        int n = C.length ;

        int i = 0 ;

        int res = 0 ;

        while(i < n)
        {
            int j = i ;

            int sum = 0 ;
            int max = 0 ;

            while(j < n && C[i] == C[j])
            {
                sum += neededTime[j] ;
                max = Math.max(max, neededTime[j]) ;
                j ++ ;
            }

            i = j ;

            res += sum - max ;

        }

        return res ;
        
    }
}
