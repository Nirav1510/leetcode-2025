// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return nums[left]; 
}

int findMinAlternative(vector<int>& nums) {
    int left = 0, n = nums.size();
    int right = nums.size() - 1;

    while (left <= right) {
        if (nums[left] <= nums[right]) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        int prev = (mid+n-1) % n;
        int next = (mid+1) % n;

        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
            return nums[mid];
        } else if(nums[mid] >= nums[left]){
            left = mid + 1;
        } else{ 
            right = mid - 1;
        }
    }
    return -1;
}