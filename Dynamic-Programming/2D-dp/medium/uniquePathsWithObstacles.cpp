// https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    // If starting or ending cell has an obstacle, return 0
    if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize first row
    for (int col = 0; col < n; col++) {
        if (grid[0][col] == 1){
            break;
        }
        dp[0][col] = 1;
    }

    // Initialize first column
    for (int row = 0; row < m; row++) {
        if (grid[row][0] == 1){
            break;
        }
        dp[row][0] = 1;
    }

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; // Obstacle blocks the path
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}
