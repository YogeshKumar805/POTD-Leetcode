class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] s=sentence.split(" ");
        int ans=0;
        for(int i=0;i<s.length;i++){
            if(s[i].indexOf(searchWord)==0){
                ans=i+1;
                break;
            }
        }
        if(ans==0){
            return -1;
        }
        else return ans;
    }
}
