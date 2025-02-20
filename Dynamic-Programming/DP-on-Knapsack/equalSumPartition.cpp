// https://leetcode.com/problems/partition-equal-subset-sum/

bool isSubsetSum(vector<int> &arr, int t){
    int n=arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(t+1, false));
    
    for(int i=0;i<n+1;i++){
        dp[i][0] = true;
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

bool equalPartition(vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum&1) return false;
    
    int t = sum/2;
    
    return isSubsetSum(arr, t);
}

// using bitwise operator
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum&1) return false;

    bitset<10001> bits(1);

    for (auto n : nums){
        bits = bits | (bits << n);
    }
    
    return bits[sum >> 1];
}