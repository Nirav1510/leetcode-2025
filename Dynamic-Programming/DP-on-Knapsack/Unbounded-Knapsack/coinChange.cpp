// https://leetcode.com/problems/coin-change/

int coinChange(vector<int>& coins, int amt) {
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amt+1, 0));

    for(int j=0;j<amt+1;j++){
        dp[0][j] = INT_MAX-1;
        if(j % coins[0] == 0){
            dp[1][j] = j/coins[0];
        }else{
            dp[1][j] = INT_MAX - 1;
        }
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<amt+1;j++){
            int exclude = dp[i-1][j];

            if(coins[i-1] <= j){
                int include = 1 + dp[i][j-coins[i-1]];
                dp[i][j] = min(include, exclude);
            }else{
                dp[i][j] = exclude;
            }
        }
    }

    return dp[n][amt] == INT_MAX - 1 ? -1 : dp[n][amt];
}

// ------ Space Optimized ------
int coinChange(vector<int>& coins, int amt) {
    vector<int> dp(amt+1, INT_MAX-1);
    dp[0] = 0;

    for (int coin : coins){
        for (int i = coin; i < amt + 1; i++){
            dp[i] = min(1 + dp[i - coin], dp[i]);
        }
    }

    return dp[amt] == INT_MAX - 1 ? -1 : dp[amt];
}