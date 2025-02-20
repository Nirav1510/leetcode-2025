// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

int numSubsequences(vector<int>& nums, int t) {
    int n = nums.size();
    int left = 0, right = n-1;
    int mod = 1e9+7, ans = 0;

    sort(nums.begin(), nums.end());

    vector<int> power(n, 1);
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 2) % mod;
    }

    while(left<=right){
        int sum = (nums[left] + nums[right]) % mod;

        if(sum > t){
            right--;
        }else{
            ans = (ans + power[right - left]) % mod;
            left++;
        }
    }
    return ans;
}