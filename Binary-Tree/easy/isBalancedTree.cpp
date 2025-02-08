// https://leetcode.com/problems/balanced-binary-tree/

int getHeight(TreeNode *root){
    if(!root) return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    return getHeight(root) != -1;
}