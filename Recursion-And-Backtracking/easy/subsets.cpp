// https://leetcode.com/problems/subsets/

void solve(vector<int>& nums, int idx, vector<int> &curr, vector<vector<int>> &ans){
    if(idx == nums.size()){
        ans.push_back(curr);
        return;
    }

    // include
    curr.push_back(nums[idx]);
    solve(nums, idx+1, curr, ans);

    // exclude
    curr.pop_back();
    solve(nums, idx+1, curr, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> curr;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    solve(nums, 0, curr, ans);

    return ans;
}