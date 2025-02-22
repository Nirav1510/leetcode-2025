// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> length(n, 0);
    
    for(int i=0;i<n;i++){
        length[i] = i+1;
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int exclude = dp[i-1][j];
            
            if(length[i-1] <= j){
                int include = price[i-1] + dp[i][j-length[i-1]];
                dp[i][j] = max(include, exclude);
            }else{
                dp[i][j] = exclude;
            }
        }
    }
    
    return dp[n][n];
}