// https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(m == 0 && n == 0) return 0;
    if(m == 0 || n == 0) return 1;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // single row
    for(int col=0;col<n;col++){
        if(grid[0][col] == 1){
            dp[0][col] = 0;
            break;
        }else{
            dp[0][col] = 1;
        }
    }

    // single column
    for(int row=0;row<m;row++){
        if(grid[row][0] == 1){
            dp[row][0] = 0;
            break;
        }else{
            dp[row][0] = 1;
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}