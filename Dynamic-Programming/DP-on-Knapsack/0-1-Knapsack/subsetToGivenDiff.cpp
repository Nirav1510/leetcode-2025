// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

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

int countPartitions(vector<int>& arr, int d) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
    
    if ((totalSum + d) % 2 != 0) {
        return 0;
    }
    
    int s1 = (totalSum + d)/2;
    
    return perfectSum(arr, s1);
}