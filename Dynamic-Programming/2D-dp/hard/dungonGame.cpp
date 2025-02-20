// https://leetcode.com/problems/dungeon-game/

int calculateMinimumHP(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[m-1][n-1] = max(1, 1 - mat[m-1][n-1]);

    // last row
    for(int col=n-2;col>=0;col--){
        dp[m-1][col] = max(1, dp[m-1][col+1] - mat[m-1][col]);
    }

    // last col
    for(int row=m-2;row>=0;row--){
        dp[row][n-1] = max(1, dp[row+1][n-1] - mat[row][n-1]);
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int minHealth = min(dp[i+1][j], dp[i][j+1]) - mat[i][j];
            dp[i][j] = max(1, minHealth);
        }
    }

    return dp[0][0];
}