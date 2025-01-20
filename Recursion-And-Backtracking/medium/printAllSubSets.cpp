// https://leetcode.com/problems/subsets-ii/

void solve(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &ans){
    ans.push_back(temp);

    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i] == nums[i-1]){
            continue;
        }
        temp.push_back(nums[i]);
        solve(nums, i+1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());
    solve(nums, 0, temp, ans);

    return ans;
}