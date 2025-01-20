// https://leetcode.com/problems/combination-sum/

void solve(vector<int>& candidates, int t, vector<int> &temp, vector<vector<int>> &ans, int start){
    if(t == 0){
        ans.push_back(temp);
        return;
    }

    for(int i=start;i<candidates.size();i++){
        if(t-candidates[i] >= 0){
            temp.push_back(candidates[i]);
            solve(candidates, t-candidates[i], temp, ans, i);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    solve(candidates, target, temp, ans, 0);
    return ans;
}