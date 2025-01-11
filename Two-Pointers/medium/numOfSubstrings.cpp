// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

int numberOfSubstrings(string s) {
    vector<int> hash(3,-1);
    int n = s.size(), cnt = 0;

    for(int i=0;i<n;i++){
        hash[s[i] - 'a'] = i;

        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
            cnt += min(hash[0], min(hash[1], hash[2])) + 1;
        }
    }
    
    return cnt;
}


int numberOfSubstrings(string s) {
    unordered_map<char, int> freq;
    int i = 0, ans = 0, n = s.size();

    for (int j = 0; j < n; j++) {
        freq[s[j]]++;

        while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
            ans += n - j;
            freq[s[i]]--;
            i++;
        }
    }

    return ans;
}