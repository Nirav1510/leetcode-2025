// https://leetcode.com/problems/minimum-path-sum/

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    // single row
    for(int col=1;col<n;col++){
        dp[0][col] = dp[0][col-1] + grid[0][col];
    }

    // single column
    for(int row=1;row<m;row++){
        dp[row][0] = dp[row-1][0] + grid[row][0];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[m-1][n-1];
}