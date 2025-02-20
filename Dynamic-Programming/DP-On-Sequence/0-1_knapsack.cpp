// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

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