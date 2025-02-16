// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

void getPaths(Node* root, vector<int> &curr, vector<vector<int>> &ans){
    if(!root){
        return;
    }
    
    curr.push_back(root->data);
    if(!root->left && !root->right){
        ans.push_back(curr);
    }else{
        getPaths(root->left, curr, ans);
        getPaths(root->right, curr, ans);
    }
    curr.pop_back();
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    
    vector<int> curr;
    
    getPaths(root, curr, ans);
    
    return ans;
}