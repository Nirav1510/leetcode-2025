// https://leetcode.com/problems/distinct-subsequences/

int numDistinct(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<unsigned long long int>> dp(n+1, vector<unsigned long long int>(m+1, 0));

    for(int i=0;i<n+1;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][m];
}