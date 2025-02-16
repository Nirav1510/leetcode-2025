// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

vector<int> topView(TreeNode *root) {
    vector<int> ans;
    
    if(!root) return ans;
    
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* curr = it.first;
        int verticalLevel = it.second;
        
        if(mp.find(verticalLevel) == mp.end()){
            mp[verticalLevel] = curr->data;
        }
        
        if(curr->left){
            q.push({curr->left, verticalLevel - 1});
        }
        if(curr->right){
            q.push({curr->right, verticalLevel + 1});
        }
    }
    
    for(auto &it : mp){
        ans.push_back(it.second);
    }

    return ans;
}