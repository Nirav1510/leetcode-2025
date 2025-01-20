// https://www.geeksforgeeks.org/problems/subset-sums2234/1

void solve(vector<int> &arr, int left, int right, vector<int> &ans, int sum){
    if(left>right){
        ans.push_back(sum);
        return;
    }
    
    solve(arr, left+1, right, ans, sum);
    solve(arr, left+1, right, ans, sum+arr[left]);
}

vector<int> subsetSums(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    
    solve(arr, 0, n-1, ans, 0);
    return ans;
}