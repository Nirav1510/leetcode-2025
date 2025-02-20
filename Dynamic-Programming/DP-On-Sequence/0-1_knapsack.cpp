// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// ------ Bottom Up Approach ------
int knapSack(int c, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<c+1;j++){
            int exclude = dp[i-1][j];
            
            if(wt[i-1] <= j){
                int include = val[i-1] + dp[i-1][j-wt[i-1]];
                dp[i][j] = max(include, exclude);
            }else{
                dp[i][j] = exclude;
            }
        }
    }
    return dp[n][c];
}

// ------ Top Down Approach -----
int solve(int c, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
    if(n == 0 || c == 0) return 0;
    
    if(dp[n][c] != -1) return dp[n][c];
    
    int exclude = solve(c, val, wt, n-1, dp);
    
    if(wt[n-1] <= c){
        int include = val[n-1] + solve(c-wt[n-1], val, wt, n-1, dp);
        return dp[n][c] = max(include, exclude);
    }else{
        return dp[n][c] = exclude;
    }
}

int knapSack(int c, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(c+1, -1));
    
    int ans = solve(c, val, wt, n, dp);
    return ans;
}