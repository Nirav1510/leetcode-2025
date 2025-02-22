// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1


// ------- Bottom-Up ---------
int lcs(string& a, string& b) {
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

// ------- Top-Down ---------
int solve(string& a, string& b, int n, int m, vector<vector<int>>& dp){
    if(n == 0 || m == 0) return 0;
    
    if(dp[n][m] != -1) return dp[n][m];
    
    if(a[n-1] == b[m-1]){
        return dp[n][m] = 1 + solve(a, b, n-1, m-1, dp);
    }else{
        return dp[n][m] = max(solve(a, b, n-1, m, dp), solve(a, b, n, m-1, dp));
    }
}

int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    return solve(a, b, n, m, dp);
}