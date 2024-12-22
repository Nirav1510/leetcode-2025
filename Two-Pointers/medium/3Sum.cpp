vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        int target = -nums[i];
        int j=i+1, k = n-1;

        while(j<k){
            int sum = nums[j] + nums[k];

            if(sum == target){
                ans.push_back({nums[i], nums[j], nums[k]});

                while(j<k && nums[j] == nums[j+1]) j++;
                while(j<k && nums[k] == nums[k-1]) k--;

                j++;
                k--;
            }else if(sum > target){
                k--;
            }else{
                j++;
            }
        }
    }
    return ans;
}