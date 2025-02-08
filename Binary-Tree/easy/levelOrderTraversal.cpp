// https://leetcode.com/problems/binary-tree-level-order-traversal/

void getLevelOrder(TreeNode *root, int level, vector<vector<int>> &ans){
    if(!root) return;

    if(level == ans.size()){
        ans.push_back({});
    }

    ans[level].push_back(root->val);

    getLevelOrder(root->left, level+1, ans);
    getLevelOrder(root->right, level+1, ans);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    getLevelOrder(root, 0, ans);

    return ans;
}

// -------- using BFS --------

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans; 
    
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(level);
    }

    return ans;
}