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

// ------- Bottom up approach ------
int helper(int i, int j, vector<vector<int>>& dp){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int down = helper(i-1, j, dp);
    int right = helper(i, j-1, dp);

    return dp[i][j] = down + right;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(m-1, n-1, dp);
}

// ------ Mathmatical solution ------
int uniquePaths(int m, int n) {
    int N = m+n-2;
    int r = m-1;
    double res = 1;

    for(int i=1;i<=r;i++){
        res = res * (N-r+i);
        res = res/i;
    }

    return (int)res;
}