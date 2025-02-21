// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference

vector<int> getSubsetSum(vector<int> &nums) {
    vector<int> ans;
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum+1; j++) {
            if (j >= nums[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (int j = 0; j <= sum / 2; j++) {
        if (dp[n][j]) {
            ans.push_back(j);
        }
    }

    return ans;
}  

int minDifference(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> validSubsetSum = getSubsetSum(nums);

    int res = INT_MAX;
    for (int n : validSubsetSum) {
        res = min(res, abs(sum - 2 * n));
    }

    return res;
}