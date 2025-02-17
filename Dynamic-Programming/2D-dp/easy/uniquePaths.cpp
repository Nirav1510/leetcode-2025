// https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n) {
    if(m == 0 && n == 0) return 0;
    if(m == 0 || n == 0) return 1;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // single row
    for(int col=0;col<n;col++){
        dp[0][col] = 1;
    }

    // single column
    for(int row=0;row<m;row++){
        dp[row][0] = 1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}