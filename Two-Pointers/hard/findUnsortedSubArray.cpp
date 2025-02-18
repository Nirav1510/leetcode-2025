// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

int findUnsortedSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;

    int left = 0, right = n - 1;

    // Find left boundary
    while (left < n - 1 && nums[left] <= nums[left + 1]) {
        left++;
    }
    if (left == n - 1) return 0;  // Already sorted case

    // Find right boundary
    while (right > 0 && nums[right] >= nums[right - 1]) {
        right--;
    }

    // Find min and max in the unsorted subArray
    int min_val = *min_element(nums.begin() + left, nums.begin() + right + 1);
    int max_val = *max_element(nums.begin() + left, nums.begin() + right + 1);

    // Extend left boundary if needed
    while (left > 0 && nums[left - 1] > min_val) {
        left--;
    }

    // Extend right boundary if needed
    while (right < n - 1 && nums[right + 1] < max_val) {
        right++;
    }

    return right - left + 1;
}
