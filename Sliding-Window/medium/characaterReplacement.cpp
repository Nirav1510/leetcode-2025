// https://leetcode.com/problems/longest-repeating-character-replacement/

int characterReplacement(string s, int k) {
    int n = s.length();
    unordered_map<char, int> charCount; 
    int maxFreq = 0;                    
    int maxLength = 0;                  
    int start = 0;                      

    for (int end = 0; end < n; end++) {
        charCount[s[end]]++;
        maxFreq = max(maxFreq, charCount[s[end]]);

        while ((end - start + 1) - maxFreq > k) {
            charCount[s[start]]--;
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}