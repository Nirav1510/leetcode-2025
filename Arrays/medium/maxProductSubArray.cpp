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