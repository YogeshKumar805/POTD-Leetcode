class Solution {
public:
    int n;
    char vow[26]={0}; //  vowels & consonants mapped to 0~5
    void set_type(){
        // Initialize all characters as consonants 5
        memset(vow, 5, sizeof(vow));
        vow[0] = 0, vow['e'-'a'] = 1, vow['i'-'a'] = 2, vow['o'-'a'] = 3,
        vow['u'-'a'] = 4; // type for vowels
    }

    // Function computes the number at most k consonants
    inline long long lessEq(string& word, int k) {
        int lastPos[5]={-1}; // last position of each vowel
        int freq[6]={0}; // 0-4 for vowl 5 for consonants)
        long long ans=0;   // count of valid substrings

        int cntVow=0;// count different vowels in the current window
        for (int l=0, r=0; r<n; r++) {
            int type=vow[word[r]-'a']; // Get the type

            if (type < 5){
                lastPos[type]=r; // last position of the vowel
                if (freq[type]==0) cntVow++;
            }

            freq[type]++; // Increase the freq

            // Shrink the window if the number of consonants exceeds k
            while (freq[5] > k) { // freq[5] tracks consonants
                type=vow[word[l]-'a'];
                freq[type]--; 
                if (type<5 && freq[type]==0) cntVow--;
                l++;          // Move left pointer
            }
            int minPos=*min_element(lastPos, lastPos+5);
        //    cout << freq[5] << endl;
            // count the number of valid substrings
            if (cntVow==5)
                ans+=(minPos-l+1); // valid substrings ending at r
        }
        return ans;
    }

    // Main function to count the substrings based on the given k value
    long long countOfSubstrings(string& word, int k) {
        set_type();

        n = word.size(); // Store the length of the word

        // Return the number of substrings with at most k consonants minus
        // those with at most k-1 consonants
        return k==0? lessEq(word, 0):lessEq(word, k)-lessEq(word, k-1);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
