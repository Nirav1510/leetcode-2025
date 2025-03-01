// https://leetcode.com/problems/triangle/

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0;i<n;i++){
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
}