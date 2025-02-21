// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// ------ bottom-up approach ------
bool isSubsetSum(vector<int>& arr, int t) {
    int n = arr.size();
    vector<vector<bool>>dp(n+1, vector<bool>(t+1, 0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0] = 1;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<t+1;j++){
            bool exclude = dp[i-1][j];
            
            if(arr[i-1] <= j){
                bool include = dp[i-1][j-arr[i-1]];
                dp[i][j] = include || exclude;
            }else{
                dp[i][j] = exclude;
            }
        }
    }
    
    return dp[n][t];
}

// ------- top-down approach ------
bool solve(vector<int>& arr, int t, int i, vector<vector<int>>& dp){
    if(t == 0) return 1;
    
    if(i == arr.size()) return 0;
    
    if(dp[i][t] != -1) return dp[i][t];
    
    bool exclude = solve(arr, t, i+1, dp);
    
    if(arr[i] <= t){
        bool include = solve(arr, t-arr[i], i+1, dp);
        return dp[i][t] = include || exclude;
    }else{
        return dp[i][t] = exclude;
    }
}

bool isSubsetSum(vector<int>& arr, int t) {
    int n = arr.size();
    vector<vector<int>>dp(n+1, vector<int>(t+1, -1));
    
    return solve(arr, t, 0, dp);
}

