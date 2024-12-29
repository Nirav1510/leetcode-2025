// https://leetcode.com/problems/longest-substring-without-repeating-characters/

int lengthOfLongestSubstring(string s) {
    int start = 0, ans = 0;
    unordered_map<char, int> mp;

    for(int end = 0; end<s.length(); end++){
        char c = s[end];

        if(mp.find(c) != mp.end() && mp[c] >= start){
            start = mp[c] + 1;
        }

        mp[c] = end;
        int length = end-start+1;
        ans = max(ans, length);
    }
    
    return ans;
}