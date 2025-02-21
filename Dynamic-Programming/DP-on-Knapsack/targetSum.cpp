// https://leetcode.com/problems/target-sum/

int perfectSum(vector<int>& arr, int t) {
    if (t < 0 || t > 1e6) return 0; // Prevent large memory allocation

    vector<int> dp(t + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        for (int j = t; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[t];
}

int findTargetSumWays(vector<int>& arr, int d) {
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
    if ((totalSum + d) % 2 != 0 || (totalSum + d) < 0) return 0;
    
    long long s1 = (totalSum + d) / 2;
    if (s1 > 1e6) return 0;  

    return perfectSum(arr, s1);
}