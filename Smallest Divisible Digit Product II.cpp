class Solution {

    String num; 
    int allowedPrimes[] = {2, 3, 5, 7}; 
    private boolean isReqMet(int[] freq) {
        for(int p: allowedPrimes) {
            if(freq[p] > 0) return false; 
        }
        return true; 
    }
    private StringBuilder getNum(int[] freq, int pos, int len, StringBuilder cur, boolean flag) {

        if (pos == len) {
            if (isReqMet(freq))
                return cur;
            return null;
        }
        for(int i = 1; i <= 9; i++) {
            char c = (char)('0' + i); 
            if (!flag && pos < num.length() && c < num.charAt(pos))
                continue; 
            // can I add this digit
            // What it is going to contribute? 
            // means if it's 8 -> it contributes 3 2's.
            // if 6 -> 1-2 & 1-3. 
            // and so on. 
            int curFreq[] = freq.clone(); 
            for(int _p: allowedPrimes) {
                int t = i; 
                while(t % _p == 0) {
                    curFreq[_p]--; 
                    t/=_p; 
                } 
                curFreq[_p] = Math.max(0, curFreq[_p]); 
            }

            // So if I choose current digit. 
            cur.append(c); 
            StringBuilder res = getNum(curFreq, pos + 1, len, cur, flag || (pos < num.length() && num.charAt(pos) < c)); 
            if(res != null) return res; 
            // backtrack 
            cur.deleteCharAt(cur.length() - 1); 
        }

        // Try for each length 
        // First we try to form for exact length length = n. If not possible, just keep adding 1 to it until we get our answer. 
        return null; 
    }
    public String smallestNumber(String num, long t) {
        // number greate than num, and product of digits divisible by t.
        // one thing is 2, 3, 5, 7 should be prime factors of t because if 11 or >= 11 comes then we can not get two digits whose product is a prime number. 
        this.num = num; 
        int freq[] = new int[10]; 
        for(int p: allowedPrimes) {
            while(t % p == 0) {
                freq[p]++; 
                t/= p; 
            }
        }

        if(t > 1) return "-1"; // not possible. 

        // Now we need a number which is greater than num and whose divisors are 2, 3, 5, 7 using occurences of 2, 3, 5, 7 that we have, 

        // build for length n 
        StringBuilder ans = new StringBuilder(); 
        for(int i = num.length(); i < num.length() + 10; i++) {
            StringBuilder res = getNum(freq, 0, i, ans, i > num.length() ? true :false); // [freq, pos] 
            if(res != null) return res.toString(); 
        }
        
        return "-1"; 
    }
}
