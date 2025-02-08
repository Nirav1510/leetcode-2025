// https://leetcode.com/problems/binary-tree-inorder-traversal/

void getInOrder(TreeNode *root, vector<int> &ans){
    if(!root){
        return;
    }

    getInOrder(root->left, ans);
    ans.push_back(root->val);
    getInOrder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    getInOrder(root, ans);
    return ans;
}