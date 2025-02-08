// https://leetcode.com/problems/binary-tree-preorder-traversal/

void getPreOrder(TreeNode *root, vector<int> &ans){
    if(!root){
        return;
    }

    ans.push_back(root->val);
    getPreOrder(root->left, ans);
    getPreOrder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    getPreOrder(root, ans);
    return ans;
}