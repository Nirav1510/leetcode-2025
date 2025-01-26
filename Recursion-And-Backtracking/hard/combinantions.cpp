// https://leetcode.com/problems/combinations/

void solve(int idx, vector<int> &ip, vector<int> &op, vector<vector<int>> &ans, int k){
    if(op.size() == k){
        ans.push_back(op);
        return;
    }

    for(int i=idx;i<ip.size();i++){
        op.push_back(ip[i]);
        solve(i+1, ip, op, ans, k);
        op.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> ip(n, 0);
    for(int i=0;i<n;i++){
        ip[i] = i+1;
    }

    vector<vector<int>> ans;
    vector<int> op;
    solve(0, ip, op, ans, k);

    return ans;
}