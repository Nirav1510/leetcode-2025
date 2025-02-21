// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

int perfectSum(vector<int>& arr, int t) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));

    for(int i=0;i<n+1;i++){
        dp[i][0] = 1;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=0;j<t+1;j++){
            int exclude = dp[i-1][j];
            
            if(arr[i-1] <= j){
                int include = dp[i-1][j-arr[i-1]];
                dp[i][j] = include + exclude;
            }else{
                dp[i][j] = exclude;
            }
        }
    }
    
    return dp[n][t];
}