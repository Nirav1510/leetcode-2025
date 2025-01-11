// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

long long countSubArrays(vector<int>& nums, long long k) {
    long long ans = 0, n = nums.size(), sum = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
        sum += nums[j];

        while (sum * (j - i + 1) >= k) {
            sum -= nums[i];
            i++;
        }

        ans += (j - i + 1);
    }
    
    return ans;
} 