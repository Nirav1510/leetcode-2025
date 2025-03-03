// https://leetcode.com/problems/is-subsequence/

bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while(i < n && j < m){
        if(s[i] == t[j]) i++;
        j++;
    }
    return i == n;
}

// ----------- using lcs --------------
bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m] == s.size();
}