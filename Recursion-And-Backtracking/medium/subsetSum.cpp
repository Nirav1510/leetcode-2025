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


// iterative approach
vector<int> subsetSums(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    
    ans.push_back(0);
    
    for(int i=0;i<n;i++){
        int m = ans.size();
        for(int j=0;j<m;j++){
            ans.push_back(ans[j] + arr[i]);
        }
    }
    
    return ans;
}