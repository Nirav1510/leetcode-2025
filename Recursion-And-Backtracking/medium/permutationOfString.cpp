// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

void solve(int idx, string &s, map<string, int> &mp){
    if(idx == s.size()){
        mp[s]++;
        return;
    }
    
    for(int i=idx;i<s.size();i++){
        swap(s[idx], s[i]);
        solve(idx+1, s, mp);
        swap(s[idx], s[i]);
    }
    
}

vector<string> findPermutation(string &s) {
    vector<string> ans;
    map<string, int> mp;
    solve(0, s, mp);
    
    for(auto &it : mp){
        ans.push_back(it.first);
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}