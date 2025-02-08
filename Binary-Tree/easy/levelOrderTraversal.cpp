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