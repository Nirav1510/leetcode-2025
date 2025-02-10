// https://leetcode.com/problems/binary-tree-postorder-traversal/

void getPostOrder(TreeNode *root, vector<int> &ans){
    if(!root) return;

    getPostOrder(root->left, ans);
    getPostOrder(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    getPostOrder(root, ans);
    return ans;
}