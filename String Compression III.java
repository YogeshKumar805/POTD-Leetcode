class Solution {
    public String compressedString(String word) {
        String s="";
        int c=1;
        for(int i=1; i<word.length(); i++){
            if(word.charAt(i)==word.charAt(i-1) && c==9){
                s+=(c+""+word.charAt(i-1));
                c=1;
            }
            else if(word.charAt(i)==word.charAt(i-1)){
                c+=1;
            }
            else if(word.charAt(i)!=word.charAt(i-1) && c==9){
                s+=(c+""+word.charAt(i-1));
                c=1;
            }
            else if(word.charAt(i)!=word.charAt(i-1)){
                s+=(c+""+word.charAt(i-1));
                c=1;
            }
        }
        s+=c+""+word.charAt(word.length()-1);
        return s;
    }
}
