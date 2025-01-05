class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n=s.length();

        // Convert CHAR to INT values (0-25)
        int[] arr=new int[n];
        for(int i=0; i<n; i++){
            arr[i]=s.charAt(i)-'a';
        }

        // Create difference array for shifts
        int[] map=new int[n+1];
        for(int i=0; i<shifts.length; i++){
            int val=(shifts[i][2]==0)?-1:1;
            map[ shifts[i][0] ] +=val;  //Start
            map[ shifts[i][1]+1 ] +=-1*val;  //End + 1          
        }

        //Shift the INT value for the char 
        int prefixSum=0;
        for(int i=0; i<n; i++){
            prefixSum+=map[i];         
            int charAscii=(arr[i]+prefixSum)%26;
            charAscii=(charAscii+26)%26;
            
            arr[i]=charAscii;
        }


        //Convert INT to CHAR by adding a'Ascii
        StringBuilder sb=new StringBuilder();
        for(int i=0; i<n; i++){
            char ch = (char) (arr[i]+'a');
            sb.append(ch);
        }

        return sb.toString();  
    }
}
