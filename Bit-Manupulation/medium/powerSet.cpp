// https://leetcode.com/problems/subsets/

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    int totalSubsets = 1 << n; // 2^n

    for(int num=0; num<totalSubsets; num++){ 
        vector<int> curr;
        for(int j=0;j<n;j++){
            if(num & (1 << j)){ // check if jth bit is set
                curr.push_back(nums[j]);
            }
        }
        ans.push_back(curr);
    }
    
    return ans;
}