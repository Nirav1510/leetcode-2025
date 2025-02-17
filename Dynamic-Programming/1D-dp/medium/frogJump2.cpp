// https://www.geeksforgeeks.org/problems/minimal-cost/1

// TC : O(n*k), SC : O(n)
int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    
    for(int i=1;i<n;i++){
        int jumpCost = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j >= 0){
                int jump = dp[i-j] + abs(arr[i]-arr[i-j]);
                jumpCost = min(jumpCost, jump);
            }
        }
        
        dp[i] = jumpCost;
    }
    
    return dp[n-1];
}