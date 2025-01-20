// https://leetcode.com/problems/combination-sum-ii/

void solve(vector<int> &arr, int t, vector<int> &curr, vector<vector<int>> &ans, int idx){
    if(t == 0){
        ans.push_back(curr);
        return;
    }

    for(int i=idx;i<arr.size();i++){
        if(i > idx && arr[i] == arr[i-1]){
            continue;
        }
        if(arr[i] > t){
            break;
        }
        curr.push_back(arr[i]);
        solve(arr, t-arr[i], curr, ans, i+1);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    vector<int> curr;
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    solve(arr, target, curr, ans, 0);

    return ans;
}