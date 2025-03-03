string print_longest_common_subsequences(string a, string b) {
    int n = a.size(), m = b.size();
    string ans;
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
    
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}