// https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

void solve(Node* root, int sum, vector<int> &curr, vector<vector<int>> &ans){
    if(!root) return;
    
    curr.push_back(root->key);
    sum = sum - root->key;
    
    if(sum == 0){
        ans.push_back(curr);
    }
    
    solve(root->left, sum, curr, ans);
    solve(root->right, sum, curr, ans);
    
    curr.pop_back();
}

vector<vector<int>> printPaths(Node *root, int sum){
    vector<vector<int>> ans;
    if(!root) return ans;
    
    vector<int> curr;
    solve(root, sum, curr, ans);
    
    return ans;
}