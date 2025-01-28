// https://leetcode.com/problems/single-number-ii/


// TC : O(32N), SC : O(1)
int singleNumber(vector<int>& nums) {
    int ans = 0, n=nums.size();

    for(int bitIdx=0; bitIdx<32; bitIdx++){
        int count = 0;

        for(int i=0;i<n;i++){
            if(nums[i] & (1 << bitIdx)){
                count++;
            }
        }

        if(count % 3 == 1){
            ans = ans | (1 << bitIdx);
        }
    }

    return ans;
}

// another approach TC : O(N), SC : O(1)
int singleNumberOptimized(vector<int>& nums) {
    // Variables to store intermediate results
    // `ones` holds the XOR of numbers that have appeared exactly once
    // `twos` holds the XOR of numbers that have appeared exactly twice
    int ones = 0, twos = 0;

    // Traverse through the array
    for (int n : nums) {
        // Update `ones`:
        // Add the current number to `ones` if it hasn't already been added twice (`~twos` ensures this).
        // Remove the number from `ones` if it's already there (via XOR).
        ones = (ones ^ n) & ~twos;

        // Update `twos`:
        // Add the current number to `twos` if it hasn't already been added once (`~ones` ensures this).
        // Remove the number from `twos` if it's already there (via XOR).
        twos = (twos ^ n) & ~ones;
    }

    // `ones` now contains the number that appears exactly once.
    return ones;
}