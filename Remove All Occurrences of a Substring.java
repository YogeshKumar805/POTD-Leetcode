class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder sb=new StringBuilder();

        for(int i=0; i<s.length(); i++){
            sb.append(s.charAt(i));
            if(sb.length()>=part.length() && sb.substring(sb.length()-part.length()).equals(part)){
                sb.setLength(sb.length()-part.length());
            }
        }
                
        return sb.toString();
    }
}
