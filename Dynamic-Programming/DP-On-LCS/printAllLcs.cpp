// https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
    
void findAllLcs(string &a, string &b, int i, int j, string curr, set<string> &hashSet, vector<vector<int>> &dp, unordered_map<string, bool> &memo){
    if(i == 0 || j == 0){
        reverse(curr.begin(), curr.end());
        hashSet.insert(curr);
        return;
    }
    
    string key = to_string(i) + "_" + to_string(j) + "_" + curr;
    if (memo.find(key) != memo.end()) return; 
    
    if(a[i-1] == b[j-1]){
        findAllLcs(a, b, i-1, j-1, curr + a[i-1], hashSet, dp, memo);
    }else{
        if(dp[i-1][j] == dp[i][j]) findAllLcs(a, b, i-1, j, curr, hashSet, dp, memo);
        if(dp[i][j-1] == dp[i][j]) findAllLcs(a, b, i, j-1, curr, hashSet, dp, memo);
    }
    
    memo[key] = true;
}

vector<string> all_longest_common_subsequences(string a, string b) {
    int n = a.size(), m = b.size();
    vector<string> ans;
    set<string> hashSet;
    unordered_map<string, bool> memo;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    memo.clear();
    findAllLcs(a, b, n, m, "", hashSet, dp, memo);
    
    for(auto &it : hashSet){
        ans.push_back(it);
    }
    
    return ans;
}