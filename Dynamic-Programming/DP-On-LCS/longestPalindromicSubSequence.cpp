// https://leetcode.com/problems/longest-palindromic-subsequence/


// --------------- Bottom-Up ----------------
int longestPalindromeSubSequence(string a) {
    string b = a;
    reverse(b.begin(), b.end());
    
    int n = a.size(), m = b.size();
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
    
    return dp[n][m];
}

// --------------- Top-Down ----------------
int solve(string& a, string& b, int n, int m, vector<vector<int>>& dp){
    if(n == 0 || m == 0) return 0;
    
    if(dp[n][m] != -1) return dp[n][m];
    
    if(a[n-1] == b[m-1]){
        return dp[n][m] = 1 + solve(a, b, n-1, m-1, dp);
    }else{
        return dp[n][m] = max(solve(a, b, n-1, m, dp), solve(a, b, n, m-1, dp));
    }
}

int longestPalindromeSubSequence(string a) {
    string b = a;
    reverse(b.begin(), b.end());
    
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    return solve(a, b, n, m, dp);
}

// --------- Space Optimized -----------
int longestPalindromeSubSequence(string a) {
    string b = a;
    reverse(b.begin(), b.end());
    
    int n = a.size(), m = b.size();
    vector<int> curr(m+1, 0), prev(m+1, 0);
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1] == b[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    
    return prev[m];
}