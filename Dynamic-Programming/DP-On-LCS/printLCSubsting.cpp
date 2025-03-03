string printLongestCommonSubstring(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLength = 0, endIndex = 0;  // Track maximum length and ending index

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];

                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;  // Store the ending index of LCS in `a`
                }
            } else {
                dp[i][j] = 0;  // Reset if characters don't match
            }
        }
    }

    return a.substr(endIndex - maxLength, maxLength);  // Extract substring
}