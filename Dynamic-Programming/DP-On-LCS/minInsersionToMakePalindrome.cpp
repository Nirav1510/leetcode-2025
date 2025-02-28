// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

int minInsertions(string a) {
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

    return n - dp[n][m];
}