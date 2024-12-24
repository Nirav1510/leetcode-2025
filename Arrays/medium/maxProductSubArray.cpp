// https://leetcode.com/problems/maximum-product-subarray/

int maxProductSubArray(vector<int>& nums) {
    int ans = INT_MIN, preProd = 1, sufProd = 1, n=nums.size();

    for(int i=0;i<n;i++){
        if(preProd == 0){
            preProd = 1;
        }

        if(sufProd == 0){
            sufProd = 1;
        }

        preProd *= nums[i];
        sufProd *= nums[n-i-1];

        ans = max(ans, max(preProd, sufProd));
    }
    return ans;
}

// Kedane's algorithm

int maxProductSubArray2(vector<int>& nums) {
    int ans = nums[0], currMax = nums[0], currMin = nums[0], n=nums.size();

    for(int i=1;i<n;i++){
        int temp = currMax;
        currMax = max(nums[i], max(currMax*nums[i], currMin*nums[i]));
        currMin = min(nums[i], min(temp*nums[i], currMin*nums[i]));

        ans = max(ans, currMax);
    }

    return ans;
}