// https://leetcode.com/problems/find-k-closest-elements/

// Time Complexity: O((n+k)logk), Space Complexity: O(k)
vector<int> findClosestElements(vector<int>& nums, int k, int x) {
    priority_queue<pair<int, int>> maxHeap;

    for(int n : nums){
        int key = abs(n - x);
        maxHeap.push({key, n});

        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }

    vector<int> ans;
    while(!maxHeap.empty()){
        int num = maxHeap.top().second;
        maxHeap.pop();

        ans.push_back(num);
    }

    sort(ans.begin(), ans.end());

    return ans;
}


// another solution TC: O(n-k) SC: O(1)
vector<int> findClosestElements(vector<int>& nums, int k, int x) {
    vector<int> ans;
    int n = nums.size();

    int left = 0, right = n -1;

    while (right - left + 1 > k) {
        if (abs(nums[left] - x) > abs(nums[right] - x)) {
            left++;
        } else {
            right--;
        }
    }

    for (int i = left; i <= right; i++) {
        ans.push_back(nums[i]);
    }

    return ans;
}

// using binary search TC: O(log(n-k)) + O(k), SC: O(1)
vector<int> findClosestElements(vector<int>& nums, int k, int x) {
    int left = 0, right = nums.size() - k;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Ensure mid + k is within bounds; right is at most (N - K)
        if (x - nums[mid] > nums[mid + k] - x) {
            left = mid + 1;  // Move right to find a closer range
        } else {
            right = mid;  // Move left
        }
    }

    // Extract the k closest elements starting from 'left'
    return vector<int>(nums.begin() + left, nums.begin() + left + k);
}
