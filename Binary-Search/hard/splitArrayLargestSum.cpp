// https://leetcode.com/problems/split-array-largest-sum/description/

bool isPossible(const vector<int>& nums, int maxSum, int maxSplits) {
    int subArrayCount = 1, sum = 0;

    for (int n : nums) {
        if (n > maxSum) return false; // Single element exceeds maxSum, not possible

        sum += n;
        if (sum > maxSum) {
            subArrayCount++; // Start a new subArray
            sum = n;         // Reset sum to the current element
        }

        if (subArrayCount > maxSplits) {
            return false; // Too many subArrays required
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int k) {
    if (nums.empty()) return 0; // Handle edge case for empty array

    int low = *max_element(nums.begin(), nums.end()); // Minimum possible largest sum
    int high = accumulate(nums.begin(), nums.end(), 0); // Maximum possible largest sum
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, mid, k)) {
            ans = mid;       // Update answer to the current valid largest sum
            high = mid - 1;  // Try for a smaller largest sum
        } else {
            low = mid + 1;   // Increase the minimum largest sum
        }
    }

    return ans;
}
