// https://leetcode.com/problems/minimum-falling-path-sum/

int minFallingPathSum(vector<vector<int>>& mat) {
    int n = mat.size();

    int dp[n][n];

    for(int j=0;j<n;j++){
        dp[0][j] = mat[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int down = mat[i][j] + dp[i-1][j];

            int leftDiagonal = mat[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal = INT_MAX;
            }

            int rightDiagonal = mat[i][j];
            if (j + 1 < n) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal = INT_MAX; 
            }

            dp[i][j] = min({down, leftDiagonal, rightDiagonal});
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        ans = min(ans, dp[n - 1][j]);
    }

    return ans;
}