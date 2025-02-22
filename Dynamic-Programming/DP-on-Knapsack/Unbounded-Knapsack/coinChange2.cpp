// https://leetcode.com/problems/coin-change-ii/

// ----- Recursion -----
int change(int amt, vector<int>& coins) {
    if (amt == 0) return 1;
    if (amt < 0) return 0;

    int ans = 0;
    for (int coin : coins) {
        ans += change(amt - coin, coins);
    }

    return ans;
}

// ----- Memoization -----
int solve(vector<int>& coins, int idx, int amt, vector<vector<int>>& dp) {
    if (amt == 0) return 1;
    if (amt < 0) return 0;
    if (idx >= coins.size()) return 0;

    if (dp[idx][amt] != -1) return dp[idx][amt];

    int include = solve(coins, idx, amt - coins[idx], dp);
    int exclude = solve(coins, idx + 1, amt, dp);

    return dp[idx][amt] = include + exclude;
}

int change(int amt, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amt + 1, -1));
    return solve(coins, 0, amt, dp);
}

// ----- Tabulation -----
int change(int amt, vector<int>& coins) {
    int n = coins.size();
    vector<vector<uint64_t>> dp(n+1, vector<uint64_t>(amt+1, 0));

    for(int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < amt+1; j++) {
            uint64_t exclude = dp[i-1][j];

            if(coins[i-1] <= j) {    
                uint64_t include = dp[i][j - coins[i-1]];
                dp[i][j] = (include + exclude);
            } else {
                dp[i][j] = exclude;
            }
        }
    }

    return dp[n][amt];
}


// ----- Space Optimized Solution -----
int change(int amt, vector<int>& coins) {
    vector<uint64_t> dp(amt + 1, 0);
    dp[0] = 1; 

    for (int coin : coins) {
        for (int j = coin; j <= amt; j++) {
            dp[j] = (dp[j] + dp[j - coin]);
        }
    }

    return dp[amt];
}