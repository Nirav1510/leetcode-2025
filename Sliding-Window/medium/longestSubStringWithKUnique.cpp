// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string &s, int k) {
    unordered_map<char, int> mp;
    int ans = -1;
    int i = 0, j = 0, n = s.length();
    
    while(j<n){
        mp[s[j]]++;
        
        if(mp.size() == k){
            ans = max(ans, j-i+1);
        }else if(mp.size() > k){
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}